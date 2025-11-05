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

  bool CreateTable();
};