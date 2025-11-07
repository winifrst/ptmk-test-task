#pragma once
#include <chrono>

class Database;

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

  std::string getLastName() const { return lastName; }
  std::string getFirstName() const { return firstName; }
  std::string getMiddleName() const { return middleName; }
  std::string getBirthDate() const { return birthDate; }
  std::string getGender() const { return gender; }

  int getAge() const;
  void saveToDatabase(Database &db) const;
};