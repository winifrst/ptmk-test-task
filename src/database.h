#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string>

class Database {
private:
  sqlite3 *db;

public:
  Database(const std::string &filename);
  ~Database();

  void CreateTable();
  void Execute(const std::string &sql);
};