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

void Database::CreateTable() {
  const char *query = "CREATE TABLE IF NOT EXISTS employees ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "last_name TEXT,"
                      "first_name TEXT,"
                      "middle_name TEXT,"
                      "birth_date TEXT,"
                      "gender TEXT,"
                      "UNIQUE(last_name, first_name, middle_name, birth_date)"
                      ");";

  Execute(query);
  std::cout << "Table 'employees' created successfully." << std::endl;
}

void Database::Execute(const std::string &query) {
  char *errMsg = nullptr;
  int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
  if (rc != SQLITE_OK) {
    std::string error = errMsg ? errMsg : "Unknown SQL error";
    sqlite3_free(errMsg);
    throw std::runtime_error("SQL error: " + error);
  }
}
