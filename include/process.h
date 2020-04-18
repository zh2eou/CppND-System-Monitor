#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);                        // constructor
  int Pid();                               
  std::string User();                      
  std::string Command();                   
  float CpuUtilization() const;                  
  void UpdateCpuUtilization(long activeJiffies, long totalJiffies);
  std::string Ram();                       
  long int UpTime();                       
  bool operator<(Process const& a) const;  

 private:
  int pid_;
  float cpu_{0};
  long prevTotal_{0};
  long prevActive_{0};
};

#endif