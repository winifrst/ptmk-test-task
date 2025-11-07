#include "common.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void remove_test_db(const std::string &db_path) {
  if (std::filesystem::exists(db_path)) {
    std::remove(db_path.c_str());
  }
}