#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    int hrs = seconds/3600;
    int mins = (seconds - hrs * 3600)/60;
    int secs = seconds - mins * 60 - hrs * 3600;
    string fmt_string;
    if (hrs < 10){ fmt_string += "0";}
    fmt_string += to_string(hrs) + ":";
    if (mins < 10){ fmt_string += "0";}
    fmt_string += to_string(mins) + ":";
    if (secs < 10){ fmt_string += "0";}
    fmt_string += to_string(secs);

    return fmt_string;
}