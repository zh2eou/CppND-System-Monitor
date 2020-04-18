#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Used to debug intermediate values
std::string System::Debug() {
  std::string temp_val = "Mem ";

  string temp, memTotal, memFree, memAvailable;
  string line;
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kMeminfoFilename);
  
    if (stream.is_open()) {
        //Read total memory
      while (line.find("Total:") ==  std::string::npos) {
        std::getline(stream, line);
      }
      std::istringstream linestream(line);
      linestream >> temp >> memTotal;
      temp_val += "Total: " + memTotal;
      // Read free memory
      while (line.find("Free:") ==  std::string::npos) {
        std::getline(stream, line);
      }
      std::istringstream linestream2(line);
      linestream2 >> temp >> memFree;
      temp_val += " Free: " + memFree;
      // Read available memory
      while (line.find("Available:") ==  std::string::npos) {
        std::getline(stream, line);
      }
      std::istringstream linestream3(line);
      linestream3 >> temp >> memAvailable;
      temp_val += " Available: " + memAvailable;
    }
    return temp_val;
}

// Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    vector<int> pids = LinuxParser::Pids();

    for (auto pid : pids) {
      Process process = Process(pid);
      process.UpdateCpuUtilization(LinuxParser::ActiveJiffies(pid), LinuxParser::Jiffies());
      processes_.push_back(Process(pid));
    }
    std::sort(processes_.begin(), processes_.end());
    return processes_; 
}

// Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }