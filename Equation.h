#pragma once
#include <string>
#include <vector>
#include <map>

class Equation {
public:
	Equation(std::string lhsVariableName, int rhsNumericValue, std::vector<std::string> rhsVariableNames);
	~Equation();

	std::string LHSVariableName();
	std::string EquationAsExpression();
	std::string RHSVariableNamesAsExpression();

	bool IsSolved();
	bool SolveEquation(std::map<std::string, int>& solvedEquations);
	int Solution();

private:
	// member variables
	std::string mLHSVariableName;
	int mRHSNumericValue; // this represents sum of all the numeric values in the RHS of the equation.

	std::vector<std::string> mRHSVariableNames;
};
