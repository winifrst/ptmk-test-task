#pragma once

#include "utils.h"
#include <random>

class Namer {
public:
  static const std::vector<std::string> &maleFirstNames();
  static const std::vector<std::string> &femaleFirstNames();
  static const std::vector<std::string> &maleMiddletNames();
  static const std::vector<std::string> &femaleMiddletNames();
  static const std::vector<std::vector<std::string>> &maleLastNames();
  static const std::vector<std::vector<std::string>> &femaleLastNames();
  static std::string getMaleFirstName(size_t index);
  static std::string getFemaleFirstName(size_t index);
  static std::string getMaleMiddleName(size_t index);
  static std::string getFemaleMiddleName(size_t index);
  static std::string getMaleLastName(char letter, size_t index);
  static std::string getFemaleLastName(char letter, size_t index);
  std::vector<std::string> generateLastNamesForLetter(char letter, bool male);
};
