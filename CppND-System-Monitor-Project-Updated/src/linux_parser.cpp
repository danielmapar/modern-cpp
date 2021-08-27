#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iomanip>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;
using std::accumulate;
using std::stol;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// DONE: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
	float totalMem = 0;
    float freeMem = 0;
  	string line;
  	string key;
    string value;
    std::ifstream fileStream(kProcDirectory + kMeminfoFilename);
    if (fileStream.is_open()) {
        while (std::getline(fileStream, line)) {
            std::istringstream lineStream(line);
            lineStream >> key >> value;
            if (key == "MemTotal:") {
                totalMem = stof(value);
            } else if (key == "MemFree:") {
                freeMem = stof(value);
            }
        }
    }
  	return (totalMem-freeMem)/totalMem;
}

// DONE: Read and return the system uptime
long LinuxParser::UpTime() {
  	string line;
  	long upTime = 0;
    std::ifstream stream(kProcDirectory + kUptimeFilename);    
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream lineStream(line);
        lineStream >> upTime;        
    }
    return upTime;
}

// DONE: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
	return LinuxParser::ActiveJiffies() + LinuxParser::IdleJiffies();
}

// DONE: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) { 
  	string notNecessary;
  	string line;
  	long uTime = 0;
    long sTime = 0; 
  	long cuTime = 0;
  	long csTime = 0;
  	std::ifstream fileStream(kProcDirectory + to_string(pid) + kStatFilename);
  	if (fileStream.is_open()) {
    	std::getline(fileStream, line);
    	std::istringstream lineStream(line);
      	// 13 useless valus
    	for (int idx = 0; idx < 13; idx++) {
          lineStream >> notNecessary;
        }

    	lineStream >> uTime >> sTime >> cuTime >> csTime;
  	}
  	return uTime + sTime + cuTime + csTime;
}

// DONE: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
	vector<string> cpuUtilization = LinuxParser::CpuUtilization();
  	long user = stol(cpuUtilization[CPUStates::kUser_]);
    long nice = stol(cpuUtilization[CPUStates::kNice_]);
    long system = stol(cpuUtilization[CPUStates::kSystem_]);
    long irq = stol(cpuUtilization[CPUStates::kIRQ_]);
    long softIrq = stol(cpuUtilization[CPUStates::kSoftIRQ_]);
    long steal = stol(cpuUtilization[CPUStates::kSteal_]);

	return user + nice + system + irq + softIrq + steal;
}

// DONE: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
	vector<string> cpuUtilization = LinuxParser::CpuUtilization();
	long idle = stol(cpuUtilization[CPUStates::kIdle_]);
  	long iowait = stol(cpuUtilization[CPUStates::kIOwait_]);

  	return idle + iowait;
}

// DONE: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
	vector<string> cpuUtilization;
	string line;
	string typeOfData;
  
	std::ifstream fileStream(kProcDirectory + kStatFilename);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream lineStream(line);
			while (lineStream >> typeOfData) {
				if (typeOfData == "cpu") {
					while (lineStream >> typeOfData) {
                      cpuUtilization.push_back(typeOfData);
                    }
                  	return cpuUtilization;
				}
			}
		}
	}
	return cpuUtilization;
}

// DONE: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
	string line;
	string key;
	int value = 0;
	int totalProcs = 0;
	std::ifstream fileStream(kProcDirectory + kStatFilename);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream lineStream(line);
			while (lineStream >> key >> value) {
				if (key == "processes") {
					totalProcs = value;
					break;
				}
			}
		}
	}
	return totalProcs;
}

// DONE: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
	int runningProc = 0;
	int value = 0;
	string line; 
	string key;
	std::ifstream fileStream(kProcDirectory + kStatFilename);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream lineStream(line);
			while (lineStream >> key >> value) {
				if (key == "procs_running") {
					runningProc = value;
					break;
				}
			}
		}
	}
	return runningProc;
}

// DONE: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
	string line;
	std::ifstream fileStream(kProcDirectory + to_string(pid) + kCmdlineFilename);
	if (fileStream.is_open()) {
		std::getline(fileStream, line);
		if (line != "") {
			return line;
		}
	}
	return "None";
}

// DONE: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
	string line;
	string key;
	string value;

	std::stringstream ramStream;

	std::ifstream fileStream(kProcDirectory + to_string(pid) + kStatusFilename);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream lineStream(line);
			lineStream >> key >> value;
			if (key == "VmSize:") {
				ramStream << std::fixed << std::setprecision(1) << stof(value) / 1000;
				return ramStream.str();
			}
		}
	}
	return "0";
}

// DONE: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
	string line;
	string key;
	string value;

	std::ifstream fileStream(kProcDirectory + to_string(pid) + kStatusFilename);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::istringstream lineStream(line);
			lineStream >> key >> value;
			if (key == "Uid:") {
				return value;
			}
		}
	}
	return "0";
}

// DONE: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
	string uid;
	string line;
	string username;
	string password;
	std::ifstream fileStream(kPasswordPath);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			std::replace(line.begin(), line.end(), ':', ' ');
			std::istringstream lineStream(line);
			lineStream >> username >> password >> uid;
			if (uid == LinuxParser::Uid(pid)) {
				return username;
			}
		}
	}
	return username;
}

// DONE: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
	long startTime;
	string line; 
	string notNecessary;
	std::ifstream fileStream(kProcDirectory + to_string(pid) + kStatFilename);
	if (fileStream.is_open()) {
		std::getline(fileStream, line);
		std::istringstream lineStream(line);
		for (int i = 0; i < 21; i++) {
			lineStream >> notNecessary;
		}
		lineStream >> startTime;
		return LinuxParser::UpTime() - startTime / sysconf(_SC_CLK_TCK);
	}
	return 0;
}
