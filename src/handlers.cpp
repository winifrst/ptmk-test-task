
#include "database.h"
#include "employee.h"
#include "utils.h"

int handleAddEmployee(Database &db, int argc, char *argv[]) {
  try {
    if (!db.isTableExists("employees")) {
      db.createTable();
    }

    Employee e = parseEmployeeArgs(argc, argv);
    e.saveToDatabase(db);
    std::cout << "Added employee: " << e.getLastName() << " "
              << e.getFirstName() << ", age " << e.getAge() << std::endl;
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}

void handleListEmployees(Database &db) {
  if (!db.isTableExists("employees")) {
    db.createTable();
  }

  std::vector<Employee> employees = db.selectAllEmployees();
  if (employees.empty()) {
    std::cout << "No employees found." << std::endl;
    return;
  }

  std::cout << "=== Employee list ===" << std::endl;
  for (const auto &e : employees) {
    std::cout << e.getLastName() << " " << e.getFirstName() << " "
              << e.getMiddleName() << ", " << e.getBirthDate() << ", "
              << e.getGender() << ", age: " << e.getAge() << std::endl;
  }
}

void handleGenerateEmployees(Database &db) {
  if (!db.isTableExists("employees")) {
    db.createTable();
  }
  std::cout << "Generating employees..." << std::endl;
  auto employees = generateRandomEmployees(1000000, true);
  db.insertEmployeesPack(employees);
}

void handleQueryMenF(Database &db) {
  if (!db.isTableExists("employees")) {
    db.createTable();
  }
  auto start = std::chrono::high_resolution_clock::now();

  auto employees = db.select(0, 'F');

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Found " << employees.size() << " employees.\n";
  std::cout << "Query execution time: " << duration.count() << " ms\n";
}

void handleOptimize(Database &db) {
  if (!db.isTableExists("employees")) {
    db.createTable();
  }
  db.dropIndex("idx_gender_lastname");

  std::cout << "Running query BEFORE optimization...\n";
  auto startBefore = std::chrono::high_resolution_clock::now();
  auto employeesBefore = db.select(0, 'F');
  auto endBefore = std::chrono::high_resolution_clock::now();
  auto durationBefore = std::chrono::duration_cast<std::chrono::milliseconds>(
      endBefore - startBefore);

  std::cout << "Found " << employeesBefore.size() << " employees.\n";
  std::cout << "Execution time (before): " << durationBefore.count()
            << " ms\n\n";

  std::cout << "Applying database optimization...\n";
  db.optimize();

  std::cout << "Running query AFTER optimization...\n";
  auto startAfter = std::chrono::high_resolution_clock::now();
  auto employeesAfter = db.select(0, 'F');
  auto endAfter = std::chrono::high_resolution_clock::now();
  auto durationAfter = std::chrono::duration_cast<std::chrono::milliseconds>(
      endAfter - startAfter);

  std::cout << "Found " << employeesAfter.size() << " employees.\n";
  std::cout << "Execution time (after):  " << durationAfter.count() << " ms\n";

  if (durationAfter < durationBefore) {
    double improvement = 100.0 *
                         (durationBefore.count() - durationAfter.count()) /
                         durationBefore.count();
    std::cout << "\nOptimization improved query by " << improvement << "%.\n";
  } else {
    std::cout << "\nNo performance improvement detected.\n";
  }
}