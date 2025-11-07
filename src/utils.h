#pragma once

#include "database.h"
#include "employee.h"
#include "namer.h"

Employee parseEmployeeArgs(int argc, char *argv[]);
std::vector<Employee> generateRandomEmployees(size_t count,
                                              bool addF100 = true);
