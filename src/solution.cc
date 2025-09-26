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
  std::ofstream ofs (filename);
  ofs << "Metric,Count\n";
  ofs << "Total Entries," << logs.size() << "\n";

  int counts_404 = 0;
  int counts_500 = 0;
  int other_counts = 0;
  for (Log l : logs) {
    if (l.level == 404) {
      ++counts_404;
    } else if (l.level == 500) {
      ++counts_500;
    } else {
      ++other_counts;
    }
  }

  ofs << "404," << counts_404 << "\n";
  ofs << "500," << counts_500 << "\n";
  ofs << "Other," << other_counts;
}
