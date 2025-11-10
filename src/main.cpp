#include "database.h"
#include "employee.h"
#include "utils.h"
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
    db.createTable();
    break;

  case 2: {
    // db.createTable();

    Employee e = parseEmployeeArgs(argc, argv);
    e.saveToDatabase(db);
    std::cout << "Added employee: " << e.getLastName() << " "
              << e.getFirstName() << ", age " << e.getAge() << std::endl;
    break;
  }

  case 3: {
    // db.createTable();

    std::vector<Employee> employees = db.selectAllEmployees();
    if (employees.empty()) {
      std::cout << "No employees found." << std::endl;
      break;
    }

    std::cout << "=== Employee list ===" << std::endl;
    for (const auto &e : employees) {
      std::cout << e.getLastName() << " " << e.getFirstName() << " "
                << e.getMiddleName() << ", " << e.getBirthDate() << ", "
                << e.getGender() << ", age: " << e.getAge() << std::endl;
    }
    break;
  }
  case 4: {
    db.createTable();
    std::cout << "Generating employees..." << std::endl;
    auto employees = generateRandomEmployees(1000000, true);
    db.insertEmployeesPack(employees);
    break;
  }
  case 5: {
    auto start = std::chrono::high_resolution_clock::now();

    auto employees = db.select(0, 'F');

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Found " << employees.size() << " employees.\n";
    std::cout << "Query execution time: " << duration.count() << " ms\n";
    break;
  }
  case 6: {
    db.optimize();
    auto start = std::chrono::high_resolution_clock::now();
    auto employees = db.select(0, 'F');
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Found " << employees.size() << " employees.\n";
    std::cout << "Query execution time: " << duration.count() << " ms\n";
    break;
  }
  default:
    std::cerr << "Unknown mode: " << appMode << std::endl;
    return 1;
  }

  return 0;
}
