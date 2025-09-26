#include "solution.hpp"
#include "log.hpp"
#include "helper.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <map>

std::vector<Log> ReadLogs(const std::string& filename) {
  std::vector<Log> log_vect;
  std::ifstream ifs {filename};
  std::string file_headers;

  if (!ifs.is_open()) {
    std::cerr << "Cannot open file: " << filename << std::endl;
    return log_vect;
  }

  while (std::getline(ifs, file_headers)) {
    std::string timestamp;
    std::string timestamp2;
    int level = 0;
    std::string message;
    ifs >> timestamp >> timestamp2 >> level >> message;
    timestamp += " " + timestamp2;
    log_vect.push_back(Log(timestamp, level, message));
  }
  return log_vect;
}

std::vector<Log> Filter(const std::vector<Log>& logs, int level) {
  std::vector<Log> filtered_logs;
  for (const Log& l : logs) {
    if (l.level == level) {
      filtered_logs.push_back(l);
    }
  }
  return filtered_logs;
}

std::vector<Log> Filter(const std::vector<Log>& logs, DateTime start, DateTime end) {
  std::vector<Log> filtered_logs;
  for (const Log& l : logs) {
    DateTime date_and_time = ParseTimestamp(l.timestamp);
    if (date_and_time >= start && date_and_time <= end) {
      filtered_logs.push_back(l);
    }
  }
  return filtered_logs;
}

void WriteMetrics(const std::vector<Log>& logs, const std::string& filename) {
  std::cout << "Metric,Count\n" << std::endl;
  unsigned int counts_404 = 0;
  unsigned int counts_500 = 0;
  unsigned int other_counts = logs.size();

}
