#include "../src/database.h"
#include <cstdio>
#include <filesystem>
#include <gtest/gtest.h>

void remove_test_db(const std::string &db_path) {
  if (std::filesystem::exists(db_path)) {
    std::remove(db_path.c_str());
  }
}

TEST(DatabaseTest, CreatesDatabaseFile) {
  const std::string test_db = "test_create.db";
  remove_test_db(test_db);

  {
    Database db(test_db);
    EXPECT_TRUE(std::filesystem::exists(test_db));
  }

  remove_test_db(test_db);
}

TEST(DatabaseTest, CreateTableReturnsTrueOnSuccess) {
  const std::string test_db = "test_table.db";
  remove_test_db(test_db);

  Database db(test_db);
  bool result = db.CreateTable();

  EXPECT_TRUE(result);
  remove_test_db(test_db);
}

TEST(DatabaseTest, DatabaseFileHasNonZeroSize) {
  const std::string test_db = "test_size.db";
  remove_test_db(test_db);

  {
    Database db(test_db);
    db.CreateTable();
  }

  EXPECT_TRUE(std::filesystem::exists(test_db));
  EXPECT_GT(std::filesystem::file_size(test_db), 0);

  remove_test_db(test_db);
}

TEST(DatabaseTest, WorksWithDifferentFilenames) {
  const std::string test_db1 = "test1.db";
  const std::string test_db2 = "test2.db";

  remove_test_db(test_db1);
  remove_test_db(test_db2);

  {
    Database db1(test_db1);
    Database db2(test_db2);

    EXPECT_TRUE(db1.CreateTable());
    EXPECT_TRUE(db2.CreateTable());

    EXPECT_TRUE(std::filesystem::exists(test_db1));
    EXPECT_TRUE(std::filesystem::exists(test_db2));
  }

  remove_test_db(test_db1);
  remove_test_db(test_db2);
}

TEST(DatabaseTest, TableStructureIsCorrect) {
  const std::string test_db = "test_structure.db";
  remove_test_db(test_db);

  Database db(test_db);

  EXPECT_TRUE(db.CreateTable());
  EXPECT_TRUE(db.CreateTable());

  remove_test_db(test_db);
}