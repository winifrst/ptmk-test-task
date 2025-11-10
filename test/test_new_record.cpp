#include "common.h"
TEST(DatabaseTest, ExecuteValidSQL) {
  const std::string test_db = "test_exec_ok.db";
  remove_test_db(test_db);

  Database db(test_db);
  EXPECT_NO_THROW(
      db.execute("CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT);"));
  EXPECT_NO_THROW(db.execute("INSERT INTO test (name) VALUES ('Hello');"));

  remove_test_db(test_db);
}

TEST(DatabaseTest, ExecuteThrowsOnInvalidSQL) {
  const std::string test_db = "test_exec_fail.db";
  remove_test_db(test_db);

  Database db(test_db);
  EXPECT_THROW(db.execute("CREAT TABL broken_syntax("), std::runtime_error);

  remove_test_db(test_db);
}

TEST(ParseArgsTest, ValidInputCreatesEmployee) {
  const char *argv[] = {(char *)"myApp", (char *)"2",
                        (char *)"Ivanov Petr Sergeevich", (char *)"2000-01-01",
                        (char *)"Male"};
  int argc = 5;

  Employee emp = parseEmployeeArgs(argc, const_cast<char **>(argv));

  EXPECT_EQ(emp.getLastName(), "Ivanov");
  EXPECT_EQ(emp.getFirstName(), "Petr");
  EXPECT_EQ(emp.getMiddleName(), "Sergeevich");
  EXPECT_EQ(emp.getBirthDate(), "2000-01-01");
  EXPECT_EQ(emp.getGender(), "Male");
}

TEST(ParseArgsTest, ThrowsOnMissingArguments) {
  const char *argv[] = {(char *)"myApp", (char *)"2", (char *)"Ivanov Petr",
                        (char *)"2000-01-01", (char *)"Male"};
  int argc = 5;

  EXPECT_THROW(parseEmployeeArgs(argc, const_cast<char **>(argv)),
               std::runtime_error);
}

TEST(EmployeeTest, SaveToDatabaseInsertsRow) {
  const std::string test_db = "test_employee_save.db";
  remove_test_db(test_db);

  Database db(test_db);
  db.createTable();

  Employee emp("Ivanov", "Petr", "Sergeevich", "2000-01-01", "Male");
  EXPECT_NO_THROW(emp.saveToDatabase(db));

  sqlite3 *raw_db = nullptr;
  sqlite3_open(test_db.c_str(), &raw_db);

  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(raw_db, "SELECT COUNT(*) FROM employees;", -1,
                              &stmt, nullptr);
  ASSERT_EQ(rc, SQLITE_OK);

  rc = sqlite3_step(stmt);
  ASSERT_EQ(rc, SQLITE_ROW);
  int count = sqlite3_column_int(stmt, 0);

  EXPECT_EQ(count, 1);

  sqlite3_finalize(stmt);
  sqlite3_close(raw_db);
  remove_test_db(test_db);
}

TEST(EmployeeTest, SaveToDatabaseAddDuplicate) {
  const std::string test_db = "test_employee_dup.db";
  remove_test_db(test_db);

  Database db(test_db);
  db.createTable();

  Employee emp1("Ivanov", "Petr", "Sergeevich", "2000-01-01", "Male");
  Employee emp2("Ivanov", "Petr", "Sergeevich", "2000-01-01", "Male");

  EXPECT_NO_THROW(emp1.saveToDatabase(db));
  EXPECT_NO_THROW(emp2.saveToDatabase(db));

  remove_test_db(test_db);
}