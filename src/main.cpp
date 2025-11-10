#include "handlers.h"
#include "utils.h"
#include <vector>

enum class AppMode {
  CREATE_TABLE = 1,
  ADD_EMPLOYEE,
  LIST_EMPLOYEES,
  FILL_RANDOM,
  QUERY_MALE_F,
  OPTIMIZE_QUERY
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Missing required arguments.\n";
    std::cerr << "Usage: " << argv[0] << " <mode> [args{1..6}]\n";
    return 1;
  }

  Database db = Database("employees.db");

  int appMode = std::stoi(argv[1]);
  AppMode mode = static_cast<AppMode>(appMode);

  switch (mode) {
  case AppMode::CREATE_TABLE:
    db.createTable();
    break;
  case AppMode::ADD_EMPLOYEE:
    return handleAddEmployee(db, argc, argv);
  case AppMode::LIST_EMPLOYEES:
    handleListEmployees(db);
    break;
  case AppMode::FILL_RANDOM:
    handleGenerateEmployees(db);
    break;
  case AppMode::QUERY_MALE_F:
    handleQueryMenF(db);
    break;
  case AppMode::OPTIMIZE_QUERY:
    handleOptimize(db);
    break;
  default:
    std::cerr << "Unknown mode.\n";
    return 1;
  }

  return 0;
}
