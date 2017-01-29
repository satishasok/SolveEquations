#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

#include "Equation.h"

extern void readEquations(std::istream& in, std::vector<Equation>& equations, std::map<std::string, int>& solvedEquations);
