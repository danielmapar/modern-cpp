#include <unistd.h>

#include "linux_parser.h"
#include "processor.h"

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() { 
	const long jiffies = LinuxParser::Jiffies();
	const long activeJiffies = LinuxParser::ActiveJiffies();

	if (lastActiveJiffies_ == 0 && lastJiffies_ == 0) {
		lastActiveJiffies_ = activeJiffies;	
		lastJiffies_ = jiffies;
		return lastActiveJiffies_ / lastJiffies_;
	}

  const float activeJiffiesDiff = activeJiffies - lastActiveJiffies_;
  const float jiffiesDiff = jiffies - lastJiffies_;

  lastActiveJiffies_ = activeJiffies;
  lastJiffies_ = jiffies;

  if (activeJiffiesDiff == 0) {
    return 0.0;
  } else {
  	return activeJiffiesDiff / jiffiesDiff;
  }
}