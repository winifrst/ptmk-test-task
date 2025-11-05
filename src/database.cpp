#include "database.h"

Database::Database(const std::string &filename) {
  if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
    std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
    sqlite3_close(db);
    db = nullptr;
  }
}

Database::~Database() {
  if (db) {
    sqlite3_close(db);
  }
}

bool Database::CreateTable() {
  const char *query = "CREATE TABLE IF NOT EXISTS employees ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "last_name TEXT,"
                      "first_name TEXT,"
                      "middle_name TEXT,"
                      "birth_date TEXT,"
                      "gender TEXT,"
                      "UNIQUE(last_name, first_name, middle_name, birth_date)"
                      ");";

  char *errMsg = nullptr;

  if (sqlite3_exec(db, query, nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::cerr << "SQL error: " << errMsg << "\n";
    sqlite3_free(errMsg);
    return false;
  }

  return true;
}
