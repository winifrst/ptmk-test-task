#include "database.h"
#include "employee.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// enum class AppMode {
//   CREATE_TABLE = 1,
//   ADD_EMPLOYEE,
//   LIST_EMPLOYEES,
//   FILL_RANDOM,
//   QUERY_MEN_F,
//   OPTIMIZE_QUERY
// };

Employee parseEmployeeArgs(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Missing required arguments.\n";
    std::cerr << "Usage: " << argv[0] << " <mode> [args{1..6}]\n";
    return 1;
  }

  Database db = Database("employees.db");

  int appMode = std::stoi(argv[1]);

  switch (appMode) {
  case 1:
    db.CreateTable();
    break;
  case 2: {
    Employee e = parseEmployeeArgs(argc, argv);
    e.saveToDatabase(db);
    std::cout << "Added employee: " << e.lastName << " " << e.firstName
              << ", age " << e.getAge() << std::endl;
    break;
  }
  default:
    break;
  }

  return 0;
}

Employee parseEmployeeArgs(int argc, char *argv[]) {
  if (argc < 5) {
    throw std::runtime_error(
        "Usage: myApp 2 \"Last First Middle\" YYYY-MM-DD Gender");
  }

  std::string fio = argv[2];
  std::string birthDate = argv[3];
  std::string gender = argv[4];

  std::istringstream iss(fio);
  std::vector<std::string> parts;
  std::string part;
  while (iss >> part) {
    parts.push_back(part);
  }

  if (parts.size() != 3) {
    throw std::runtime_error("FIO must contain 3 words: Last First Middle");
  }

  return Employee(parts[0], parts[1], parts[2], birthDate, gender);
}
