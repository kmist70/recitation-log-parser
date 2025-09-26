#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "solution.hpp"
#define FIVE 5

int main(int argc, char* argv[]) {
  if (argc != 3 && argc != 4 && argc != FIVE) {
    std::cerr << "Usage:\n"
              << "  " << argv[0] << " <input_log_file> <output_metrics_file>\n"
              << "  " << argv[0]
              << " <input_log_file> <output_metrics_file> <level>\n"
              << "  " << argv[0]
              << " <input_log_file> <output_metrics_file> <start date "
                 "YYYY-MM-DD HH-MM-SS> <end date YYYY-MM-DD HH-MM-SS>\n";
    return 1;
  }
  std::string input_file = argv[1];
  std::string output_file = argv[2];

  std::vector<Log> logs = ReadLogs(input_file);
  if (logs.empty()) {
    std::cerr << "No logs were read from file: " << input_file << "\n";
    return 1;
  }
  std::vector<Log> filtered_logs = logs;
  if (argc == 4) {
    filtered_logs = Filter(logs, std::stoi(argv[3]));
  } else if (argc == FIVE) {
    std::string start_str = argv[3];
    std::string end_str = argv[4];
    try {
      auto start_date = ParseTimestamp(start_str);
      auto end_date = ParseTimestamp(end_str);
      filtered_logs = Filter(logs, start_date, end_date);
    } catch (const std::invalid_argument& e) {
      std::cerr << "Error parsing dates: " << e.what() << "\n";
      return 1;
    }
  }
  WriteMetrics(filtered_logs, output_file);
  std::cout << "Metrics written to " << output_file << "\n";
  return 0;
}
