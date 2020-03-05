#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "process.h"
#include "linux_parser.h"
#include "format.h"

using std::string;
using std::to_string;
using std::vector;


// TODO: Return this process's ID
int Process::Pid() { return pid; }

void Process::Pid(int p) { 
    pid = p;
    cpu_utilization = float(LinuxParser::ActiveJiffies(pid)/sysconf(_SC_CLK_TCK))/LinuxParser::UpTime(pid);
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    return cpu_utilization; 
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return LinuxParser::UpTime(pid);
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return (cpu_utilization < a.cpu_utilization ? true : false); 
}
