#include "utils.h"

#include <ctime>
#include <iostream>
#include <random>
#include <regex>
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

  std::regex dateRegex(R"((\d{4})-(\d{2})-(\d{2}))");
  std::smatch match;

  if (!std::regex_match(birthDate, match, dateRegex)) {
    throw std::runtime_error("Birth date must be in format YYYY-MM-DD");
  }

  int year = std::stoi(match[1].str());
  int month = std::stoi(match[2].str());
  int day = std::stoi(match[3].str());

  if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
    throw std::runtime_error("Birth date has invalid year, month or day");
  }

  if (gender != "Male" && gender != "Female") {
    throw std::runtime_error("Gender must be either 'Male' or 'Female'");
  }

  return Employee(parts[0], parts[1], parts[2], birthDate, gender);
}

std::vector<Employee> generateRandomEmployees(size_t count, bool addF100) {
  std::vector<Employee> result;
  result.reserve(count + (addF100 ? 100 : 0));

  std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_int_distribution<int> yearDist(1950, 2005);
  std::uniform_int_distribution<int> monthDist(1, 12);
  std::uniform_int_distribution<int> dayDist(1, 28);
  std::uniform_int_distribution<int> letterDist(0, 25);
  std::uniform_int_distribution<int> genderDist(0, 1);
  std::uniform_int_distribution<int> lastIndexDist(0, 9);

  auto randomDate = [&](int y, int m, int d) {
    char buf[11];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d", y, m, d);
    return std::string(buf);
  };

  for (size_t i = 0; i < count; ++i) {
    bool isMale = genderDist(rng) == 0;
    char letter = 'A' + letterDist(rng);
    int idx = lastIndexDist(rng);

    std::string last = isMale ? Namer::getMaleLastName(letter, idx)
                              : Namer::getFemaleLastName(letter, idx);
    std::string first =
        isMale ? Namer::getMaleFirstName(i) : Namer::getFemaleFirstName(i);
    std::string middle =
        isMale ? Namer::getMaleMiddleName(i) : Namer::getFemaleMiddleName(i);
    std::string birth = randomDate(yearDist(rng), monthDist(rng), dayDist(rng));
    std::string gender = isMale ? "Male" : "Female";

    result.emplace_back(last, first, middle, birth, gender);
  }

  if (addF100) {
    for (int i = 0; i < 100; ++i) {
      std::string last = Namer::getMaleLastName('F', i);
      std::string first = Namer::getMaleFirstName(i);
      std::string middle = Namer::getMaleMiddleName(i);
      std::string birth =
          randomDate(yearDist(rng), monthDist(rng), dayDist(rng));
      result.emplace_back(last, first, middle, birth, "Male");
    }
  }

  return result;
}