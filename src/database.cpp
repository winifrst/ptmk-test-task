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

void Database::insertEmployeesPack(const std::vector<Employee> &employees) {
  const char *insertSQL =
      "INSERT OR IGNORE INTO employees "
      "(last_name, first_name, middle_name, birth_date, gender) "
      "VALUES (?, ?, ?, ?, ?);";

  sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
    throw std::runtime_error("Failed to prepare insert");
  }

  size_t total = employees.size();
  size_t current = 0;
  const int barWidth = 50;

  for (const auto &e : employees) {
    sqlite3_bind_text(stmt, 1, e.lastName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, e.firstName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, e.middleName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, e.birthDate.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, e.gender.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
      std::cerr << "Warning: failed to insert one record\n";
    }
    sqlite3_reset(stmt);

    current++;
    float progress = static_cast<float>(current) / total;
    int pos = static_cast<int>(barWidth * progress);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
      if (i < pos)
        std::cout << "=";
      else if (i == pos)
        std::cout << ">";
      else
        std::cout << " ";
    }
    std::cout << "] " << static_cast<int>(progress * 100.0) << " %\r";
    std::cout.flush();
  }

  std::cout << std::endl;

  sqlite3_finalize(stmt);
  sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);

  std::cout << "Pack insert completed (" << employees.size() << " rows)\n";
}

std::vector<Employee> Database::select(bool is_male, char leadingLetter) {
  std::string gender = is_male ? "Male" : "Female";

  std::string query =
      "SELECT last_name, first_name, middle_name, birth_date, gender "
      "FROM employees "
      "WHERE gender = '" +
      gender + "' AND last_name LIKE '" + leadingLetter + "%';";

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(this->db, query.c_str(), -1, &stmt, nullptr) !=
      SQLITE_OK) {
    throw std::runtime_error("Failed to prepare select query");
  }

  std::vector<Employee> result;
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    std::string last =
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
    std::string first =
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
    std::string middle =
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
    std::string birth =
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
    std::string gender =
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));

    result.emplace_back(last, first, middle, birth, gender);
  }

  sqlite3_finalize(stmt);
  return result;
}

void Database::optimize() {
  // const char *indexSQL = "CREATE INDEX IF NOT EXISTS idx_gender_lastname "
  //                        "ON employees (gender, last_name);";

  const char *indexSQL =
      "CREATE INDEX IF NOT EXISTS idx_covering ON employees (gender, "
      "last_name, first_name, middle_name, birth_date)";

  char *errMsg = nullptr;
  if (sqlite3_exec(db, indexSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::string msg = "Failed to create index: ";
    msg += errMsg ? errMsg : "";
    sqlite3_free(errMsg);
    throw std::runtime_error(msg);
  }
  std::cout << "Optimization completed: index created on (gender, last_name)\n";
}