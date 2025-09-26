#ifndef DATETIME_HPP
#define DATETIME_HPP
#include <iostream>
#include <sstream>
#include <string>
struct DateTime {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  // Constructor
  DateTime(int y, int m, int d, int h, int min, int s):
      year(y), month(m), day(d), hour(h), minute(min), second(s) {}

  // Default constructor
  DateTime(): year(0), month(0), day(0), hour(0), minute(0), second(0) {}
  // The defaulted spaceship operator provides all six comparisons.
  auto operator<=>(const DateTime&) const = default;
};

#endif  // DATETIME_HPP