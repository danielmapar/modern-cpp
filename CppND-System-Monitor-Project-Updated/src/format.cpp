#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    const long int hours = seconds / 3600;
    const long int minutes = (seconds%3600) / 60;
    const long int remainder = (seconds%3600) % 60;
    return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(remainder);
 }