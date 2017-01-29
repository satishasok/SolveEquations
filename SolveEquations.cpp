#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

#include "Input.h"
#include "EquationSolving.h"
#include "Output.h"

int main (int argc, char *argv[])
{
	// 1. Read the first argument to get the fileName for input.
	// read that file and populate the vector. 
	// Otherwise, read the Standard input and populate the vector 
	std::vector<Equation> equations; // store the list of gas-stations in here
	std::map<std::string, int> solvedEquations; // maps lhsVariable to solution, 
						 // this is populated as soon as an equation is solved. 
	if (argc < 2) {
		readEquations(std::cin, equations, solvedEquations);
	}
	else
	{
		std::ifstream in(argv[1]);
		if (not in) {
			std::perror(argv[1]);
			return EXIT_FAILURE;
		}
		readEquations(in, equations, solvedEquations);
	}


	// 2. Solve un-solved equations
	SolveEquations(equations, solvedEquations);

	// 3. Print out the output (Solved Equations)
	// The map is actually a tree, and is sorted by KEY order.
	// so just iterating thru the maps and printing key/value will print with Key sorted alphabhetically.
	OutputSolvedEquations(solvedEquations);

	return EXIT_SUCCESS;
}
