#ifndef HELPER_HPP
#define HELPER_HPP
#include <iostream>
#include <sstream>
#include <string>

#include "datetime.hpp"

#define MAX_DAY 31
#define MAX_MONTH 12
#define MAX_HOUR 23
#define MAX_MINUTE 59
#define MAX_SECOND 59

DateTime ParseTimestamp(const std::string& timestamp);
#endif  // HELPER_HPP