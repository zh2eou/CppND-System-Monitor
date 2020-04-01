#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { 
    return 1; // placeholder 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
//    long totalJiffies = LinuxParser::Jiffies();
//    long activeJiffies = LinuxParser::ActiveJiffies(Pid());
//    return float(activeJiffies) / totalJiffies;
   float utilization = 0.0f; // temp placeholder
   return utilization; 
}

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Pid()); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Pid()); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
    return cpu < a.cpu ? cpu: a.cpu;
}