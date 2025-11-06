#pragma once
#include "database.h"
#include <chrono>

class Employee {
public:
  std::string lastName;
  std::string firstName;
  std::string middleName;
  std::string birthDate;
  std::string gender;

  Employee() = default;
  Employee(std::string lastName, std::string firstName, std::string middleName,
           std::string birthDate, std::string gender);

  int getAge() const;
  void saveToDatabase(Database &db) const;
};