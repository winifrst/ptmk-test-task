#include "../src/database.h"
#include <cstdio>
#include <filesystem>
#include <gtest/gtest.h>

namespace fs = std::filesystem;

void remove_test_db(const std::string &db_path) {
  if (fs::exists(db_path)) {
    std::remove(db_path.c_str());
  }
}

TEST(DatabaseTest, CreatesDatabaseFile) {
  const std::string test_db = "test_create.db";
  remove_test_db(test_db);

  {
    Database db(test_db);
    EXPECT_TRUE(fs::exists(test_db));
  }

  remove_test_db(test_db);
}

TEST(DatabaseTest, CreateTableDoesNotThrowOnSuccess) {
  const std::string test_db = "test_table.db";
  remove_test_db(test_db);

  Database db(test_db);
  EXPECT_NO_THROW(db.createTable());

  remove_test_db(test_db);
}

TEST(DatabaseTest, DatabaseFileHasNonZeroSize) {
  const std::string test_db = "test_size.db";
  remove_test_db(test_db);

  {
    Database db(test_db);
    EXPECT_NO_THROW(db.createTable());
  }

  EXPECT_TRUE(fs::exists(test_db));
  EXPECT_GT(fs::file_size(test_db), 0);

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

    EXPECT_NO_THROW(db1.createTable());
    EXPECT_NO_THROW(db2.createTable());

    EXPECT_TRUE(fs::exists(test_db1));
    EXPECT_TRUE(fs::exists(test_db2));
  }

  remove_test_db(test_db1);
  remove_test_db(test_db2);
}

TEST(DatabaseTest, CreateTableCanBeCalledTwiceWithoutError) {
  const std::string test_db = "test_structure.db";
  remove_test_db(test_db);

  Database db(test_db);

  EXPECT_NO_THROW(db.createTable());
  EXPECT_NO_THROW(db.createTable());

  remove_test_db(test_db);
}

TEST(DatabaseTest, ThrowsOnInvalidSQL) {
  const std::string test_db = "test_invalid.db";
  remove_test_db(test_db);

  Database db(test_db);

  EXPECT_THROW(db.execute("CREAT TABL invalid_syntax("), std::runtime_error);

  remove_test_db(test_db);
}
