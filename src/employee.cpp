#include "employee.h"

Employee::Employee(std::string last, std::string first, std::string middle,
                   std::string birth, std::string g)
    : lastName(std::move(last)), firstName(std::move(first)),
      middleName(std::move(middle)), birthDate(std::move(birth)),
      gender(std::move(g)) {}

int Employee::getAge() const {
  int y, m, d;
  sscanf(birthDate.c_str(), "%d-%d-%d", &y, &m, &d);
  auto now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::tm *tm_now = std::localtime(&now);
  int age = tm_now->tm_year + 1900 - y;
  if (tm_now->tm_mon + 1 < m ||
      (tm_now->tm_mon + 1 == m && tm_now->tm_mday < d)) {
    age--;
  }

  return age;
}

void Employee::saveToDatabase(Database &db) const {
  std::string query = "INSERT INTO employees (last_name, first_name, "
                      "middle_name, birth_date, gender) VALUES ('" +
                      lastName + "', '" + firstName + "', '" + middleName +
                      "', '" + birthDate + "', '" + gender + "');";

  db.Execute(query);
}
