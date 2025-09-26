#ifndef LOG_HPP
#define LOG_HPP
#include <string>

struct Log {
  std::string timestamp;
  int level;
  std::string message;
};

#endif  // LOG_HPP