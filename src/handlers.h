#pragma once
#include "database.h"
#include "employee.h"

int handleAddEmployee(Database &db, int argc, char *argv[]);
void handleListEmployees(Database &db);
void handleGenerateEmployees(Database &db);
void handleQueryMenF(Database &db);
void handleOptimize(Database &db);