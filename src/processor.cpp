#include "processor.h"
#include "linux_parser.h"

// Return the aggregate CPU utilization
float Processor::Utilization() { 
   long total = LinuxParser::Jiffies();
   long active = LinuxParser::ActiveJiffies();
   float cpu_ = float(active - prevActive_) / (total - prevTotal_);
   prevTotal_ = total; 
   prevActive_ = active;
   return cpu_;
}