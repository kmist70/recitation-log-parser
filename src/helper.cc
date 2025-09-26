#include "helper.hpp"

DateTime ParseTimestamp(const std::string& timestamp) {
  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
  std::istringstream iss(timestamp);

  if (!(iss >> year) || iss.get() != '-' || !(iss >> month) ||
      iss.get() != '-' || !(iss >> day) || iss.get() != ' ' || !(iss >> hour) ||
      iss.get() != ':' || !(iss >> minute) || iss.get() != ':' ||
      !(iss >> second))
    throw std::invalid_argument("Invalid timestamp format.");

  if (month < 1 || month > MAX_MONTH || day < 1 || day > MAX_DAY || hour < 0 ||
      hour > MAX_HOUR || minute < 0 || minute > MAX_MINUTE || second < 0 ||
      second > MAX_SECOND)
    throw std::invalid_argument("Timestamp values out of range.");

  return {year, month, day, hour, minute, second};
}