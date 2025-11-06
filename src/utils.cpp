#include "utils.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Employee parseEmployeeArgs(int argc, char *argv[]) {
  if (argc < 5) {
    throw std::runtime_error(
        "Usage: myApp 2 \"Last First Middle\" YYYY-MM-DD Gender");
  }

  std::string fio = argv[2];
  std::string birthDate = argv[3];
  std::string gender = argv[4];

  std::istringstream iss(fio);
  std::vector<std::string> parts;
  std::string part;
  while (iss >> part) {
    parts.push_back(part);
  }

  if (parts.size() != 3) {
    throw std::runtime_error("FIO must contain 3 words: Last First Middle");
  }

  return Employee(parts[0], parts[1], parts[2], birthDate, gender);
}
