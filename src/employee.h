#pragma once
#include <string>

class Employee {
private:
  std::string lastName;
  std::string firstName;
  std::string middleName;
  std::string birthDate;
  std::string sex;

  Employee() = default;
  Employee(std::string lastName, std::string firstName, std::string middleName,
           std::string birthDate, std::string sex);
};