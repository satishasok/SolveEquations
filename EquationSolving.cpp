#include "EquationSolving.h"

// takes in all the equations, and already solved equations
// solves all the equations, and updates the solvedEquations maps with all the solved equations.
// The Maps sorted by key automatically. In this case the key is LHS variable name.
void SolveEquations(std::vector<Equation>& equations, std::map<std::string, int>& solvedEquations)
{
	bool isAllEquationsSolved = (equations.size() == solvedEquations.size());
	int currentNumberOfSolvedEquations = solvedEquations.size();
	int previousNumberOfSolvedEquations = currentNumberOfSolvedEquations;
        while (!isAllEquationsSolved) {
		
                auto iter = std::begin(equations);
                while (iter != std::end(equations)) {
                        iter->SolveEquation(solvedEquations);
                        iter++;
                }
                isAllEquationsSolved = (equations.size() == solvedEquations.size());

		if (!isAllEquationsSolved) {
			currentNumberOfSolvedEquations = solvedEquations.size();
			if (previousNumberOfSolvedEquations == currentNumberOfSolvedEquations) {
				// no additional equations could be solved
				// which mean not all equations could be solved, so break and return
				std::cerr << "Not All Equations could be solved. Printing only solved equations" << std::endl;
				break;
			}
			previousNumberOfSolvedEquations = currentNumberOfSolvedEquations;
		}
        }
}
