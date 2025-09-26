#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <fstream>
#include <vector>

#include "helper.hpp"
#include "log.hpp"

std::vector<Log> ReadLogs(const std::string& filename);

std::vector<Log> Filter(const std::vector<Log>& logs,
                        DateTime start,
                        DateTime end);

std::vector<Log> Filter(const std::vector<Log>& logs, int level);

void WriteMetrics(const std::vector<Log>& logs, const std::string& filename);

#endif  // SOLUTION_HPP
