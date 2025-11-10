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

  bool isTableExists(const std::string &tableName);
  void createTable();
  std::vector<Employee> selectAllEmployees();

  void insertEmployeesPack(const std::vector<Employee> &employees);
  void optimize();
  void dropIndex(const std::string &indexName);
  void execute(const std::string &sql);
  std::vector<Employee> select(bool is_male, char leadingLetter);
};