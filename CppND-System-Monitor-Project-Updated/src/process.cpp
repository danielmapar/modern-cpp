#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(const int pid) : pid_(pid), cpu_(CpuUtilization()) {}

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { 
	long activeJiffies = LinuxParser::ActiveJiffies(pid_);
	float seconds = (float) Process::UpTime();
	if (seconds == 0) {
		return 0;
	}
	return ((activeJiffies / sysconf(_SC_CLK_TCK)) / seconds);
}

// DONE: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// DONE: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
  return cpu_ < a.cpu_; 
}

bool Process::operator>(Process const& a) const { 
  return cpu_ > a.cpu_; 
}