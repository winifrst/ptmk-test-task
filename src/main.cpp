#include "database.h"
#include "employee.h"
#include "utils.h"

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
    db.createTable();
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
