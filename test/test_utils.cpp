#include "common.h"

TEST(UtilsTest, GenerateRandomEmployeesCount) {
  auto employees = generateRandomEmployees(1000, false);
  EXPECT_EQ(employees.size(), 1000);
}

TEST(UtilsTest, GenerateRandomEmployeesGenderDistribution) {
  auto employees = generateRandomEmployees(10000, false);

  int maleCount = 0;
  int femaleCount = 0;
  for (const auto &e : employees) {
    if (e.gender == "Male")
      maleCount++;
    else if (e.gender == "Female")
      femaleCount++;
  }

  double ratio = (double)maleCount / (maleCount + femaleCount);
  EXPECT_GT(ratio, 0.4);
  EXPECT_LT(ratio, 0.6);
}

TEST(UtilsTest, GenerateRandomEmployeesAddF100) {
  auto employees = generateRandomEmployees(1000, true);

  int fCount = 0;
  for (const auto &e : employees) {
    if (e.gender == "Male" && !e.lastName.empty() && e.lastName[0] == 'F')
      fCount++;
  }

  EXPECT_GE(fCount, 100);
}
