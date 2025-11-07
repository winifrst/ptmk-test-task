#include "common.h"

TEST(DatabaseTest, ReturnsEmptyVectorWhenNoEmployees) {
  const std::string test_db = "test_empty.db";
  remove_test_db(test_db);

  Database db(test_db);
  db.createTable();

  auto employees = db.selectAllEmployees();
  EXPECT_TRUE(employees.empty());

  remove_test_db(test_db);
}

TEST(DatabaseTest, ReturnsInsertedEmployeesSortedByLastName) {
  const std::string test_db = "test_sorted.db";
  remove_test_db(test_db);

  Database db(test_db);
  db.createTable();

  Employee e1("Ivanov", "Petr", "Sergeevich", "2000-01-01", "Male");
  Employee e2("Alekseev", "Ivan", "Petrovich", "1990-05-05", "Male");
  Employee e3("Sidorova", "Anna", "Ivanovna", "1995-07-07", "Female");

  e1.saveToDatabase(db);
  e2.saveToDatabase(db);
  e3.saveToDatabase(db);

  auto employees = db.selectAllEmployees();

  ASSERT_EQ(employees.size(), 3);
  EXPECT_EQ(employees[0].getLastName(), "Alekseev");
  EXPECT_EQ(employees[1].getLastName(), "Ivanov");
  EXPECT_EQ(employees[2].getLastName(), "Sidorova");

  remove_test_db(test_db);
}

TEST(DatabaseTest, DoesNotReturnDuplicates) {
  const std::string test_db = "test_duplicates.db";
  remove_test_db(test_db);

  Database db(test_db);
  db.createTable();

  Employee e1("Petrov", "Sergey", "Nikolaevich", "1991-09-09", "Male");
  Employee e2("Petrov", "Sergey", "Nikolaevich", "1991-09-09", "Male");

  e1.saveToDatabase(db);
  try {
    e2.saveToDatabase(db);
  } catch (...) {
  }

  auto employees = db.selectAllEmployees();

  ASSERT_EQ(employees.size(), 1);
  EXPECT_EQ(employees[0].getLastName(), "Petrov");
  EXPECT_EQ(employees[0].getFirstName(), "Sergey");

  remove_test_db(test_db);
}
