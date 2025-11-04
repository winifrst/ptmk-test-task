#include <iostream>

// enum class AppMode {
//   CREATE_TABLE = 1,
//   ADD_EMPLOYEE,
//   LIST_EMPLOYEES,
//   FILL_RANDOM,
//   QUERY_MEN_F,
//   OPTIMIZE_QUERY
// };

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Missing required arguments.\n";
    std::cerr << "Usage: " << argv[0] << " <mode> [args{1..6}]\n";
    return 1;
  }

  int app_mode = std::stoi(argv[0]);

  switch (app_mode) {
  case 1:
    break;

  default:
    break;
  }

  return 0;
}