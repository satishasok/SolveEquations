#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

#include "Equation.h"

// takes in all the equations, and already solved equations
// solves all the equations, and updates the solvedEquations maps with all the solved equations.
// The Maps sorted by key automatically. In this case the key is LHS variable name.
extern void SolveEquations(std::vector<Equation>& equations, std::map<std::string, int>& solvedEquations);
