// Input.cpp
// Handles the input file
// takes in file or std::in as a stream
// parses the file
// creates a vector of Equations object.

#include <sstream>
#include <algorithm>
#include <iostream>
#include <ostream>

#include "Input.h"

bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

std::vector<std::string> tokenizeString(std::string input, std::string delimiter)
{
	std::vector<std::string> tokens;

	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
    		token = input.substr(0, pos);
		// remove whitespaces
		token.erase(std::remove_if(token.begin(), token.end(), isspace), token.end());
		tokens.push_back(token);
    		input.erase(0, pos + delimiter.length());
	}
	// Remove whitespaces
	input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
	tokens.push_back(input);

	return tokens;
}

// Parses Equations from the input file, and create a vector.
// If it is already solved then it adds them to the solvedEquations map.
void readEquations(std::istream& in, std::vector<Equation>& equations, std::map<std::string, int>& solvedEquations)
{
        std::string line;
        while (std::getline(in, line)) {
		std::vector<std::string> equationRawDataVector = tokenizeString(line, std::string("="));

		if (equationRawDataVector.size() == 2) {
			std::string lhsVariableName = equationRawDataVector[0];
			std::string rhsRawString = equationRawDataVector[1];

			std::vector<std::string> rhsRawDataVector = tokenizeString(rhsRawString, std::string("+"));

			int rhsNumericValue = 0;
			std::vector<std::string> rhsVariableNames;
			if (rhsRawDataVector.size() >=1) {
				for (std::string rhsEntry : rhsRawDataVector) {
					if (isNumber(rhsEntry)) {
						int numericValue;
						std::istringstream(rhsEntry) >> numericValue;
						rhsNumericValue += numericValue; 
					} else {
						rhsVariableNames.push_back(rhsEntry);
					}
				}
				Equation equation(lhsVariableName, rhsNumericValue, rhsVariableNames);
				if (equation.IsSolved()) {
					solvedEquations[equation.LHSVariableName()] = equation.Solution();
				}
				equations.push_back(equation);				
			}
		} else {
			std::cerr << "Incoming Equation: \"" << line << "\"  is not valid. No RHS entry. Continue parsing next equation" << std::endl;
		}
		
	}
}
