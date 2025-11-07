#include "database.h"
#include <vector>

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

void Database::createTable() {
  const char *query = "CREATE TABLE IF NOT EXISTS employees ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "last_name TEXT,"
                      "first_name TEXT,"
                      "middle_name TEXT,"
                      "birth_date TEXT,"
                      "gender TEXT,"
                      "UNIQUE(last_name, first_name, middle_name, birth_date)"
                      ");";

  execute(query);
  std::cout << "Table 'employees' created successfully." << std::endl;
}

void Database::execute(const std::string &query) {
  char *errMsg = nullptr;
  int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
  if (rc != SQLITE_OK) {
    std::string error = errMsg ? errMsg : "Unknown SQL error";
    sqlite3_free(errMsg);
    throw std::runtime_error("SQL error: " + error);
  }
}

std::vector<Employee> Database::selectAllEmployees() {
  std::vector<Employee> result;
  const char *sql =
      "SELECT last_name, first_name, middle_name, birth_date, gender "
      "FROM employees "
      "GROUP BY last_name, first_name, middle_name, birth_date "
      "ORDER BY last_name;";

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    throw std::runtime_error("Failed to prepare SELECT");

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    auto get_string = [stmt](int col) -> std::string {
      const char *text =
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, col));
      return text ? std::string(text) : std::string();
    };

    std::string last = get_string(0);
    std::string first = get_string(1);
    std::string middle = get_string(2);
    std::string birth = get_string(3);
    std::string gender = get_string(4);

    result.emplace_back(last, first, middle, birth, gender);
  }

  sqlite3_finalize(stmt);
  return result;
}