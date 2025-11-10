#pragma once

#include "employee.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
private:
  sqlite3 *db;

public:
  Database(const std::string &filename);
  ~Database();

  void createTable();
  void execute(const std::string &sql);
  std::vector<Employee> selectAllEmployees();

  void insertEmployeesPack(const std::vector<Employee> &employees);
  std::vector<Employee> select(bool is_male, char leadingLetter);
};