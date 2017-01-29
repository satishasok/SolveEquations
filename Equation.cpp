#include <sstream>
#include <ostream>
#include <vector>
#include <map>

#include "Equation.h"

std::string VectorJoin(const std::vector<std::string>& elements, const char* const separator)
{
    switch (elements.size())
    {
        case 0:
            return "";
        case 1:
            return elements[0];
        default:
            std::ostringstream os; 
            std::copy(elements.begin(), elements.end()-1, std::ostream_iterator<std::string>(os, separator));
            os << *elements.rbegin();
            return os.str();
    }
}

Equation::Equation(std::string lhsVariableName, int rhsNumericValue, std::vector<std::string> rhsVariableNames)
: mLHSVariableName(lhsVariableName), mRHSNumericValue(rhsNumericValue), mRHSVariableNames(rhsVariableNames)
{
}

Equation::~Equation()
{
	// TODO: Additional cleanp as needed.
}

std::string Equation::LHSVariableName()
{
	return mLHSVariableName;
}

std::string Equation::EquationAsExpression()
{
	std::ostringstream os;
	os << mLHSVariableName << " = " << mRHSNumericValue;
	if (mRHSVariableNames.size() > 0) {
		os << " + " << this->RHSVariableNamesAsExpression();
	}

	return os.str();

}

std::string Equation::RHSVariableNamesAsExpression()
{
    return VectorJoin(mRHSVariableNames, " + "); 
}

bool Equation::IsSolved()
{
	return (mRHSNumericValue>=0 && mRHSVariableNames.size() == 0);
}

// Solves the Equation given a map of solved Variables
// It will be fully solved if the all the RHS Variables are already solved.
bool Equation::SolveEquation(std::map<std::string, int>& solvedEquations)
{
	mRHSVariableNames.erase(
    		std::remove_if(
        		mRHSVariableNames.begin(),
        		mRHSVariableNames.end(),
        		[&](std::string variableName) -> bool {
				auto search = solvedEquations.find(variableName);
    				if(search != solvedEquations.end()) {
					this->mRHSNumericValue += solvedEquations[variableName];
					return true;
				} else {
            				return false;
				}
        		}
    		),
    		mRHSVariableNames.end()
	);
	if (this->IsSolved()) {
		solvedEquations[mLHSVariableName] = this->mRHSNumericValue;
	}		
	return this->IsSolved();
}

// if not solved yet, it will return -1.
// if already solved, it will return the solution
int Equation::Solution()
{
	if (this->IsSolved()) {
		return mRHSNumericValue;
	} else {
		return -1;
	}
}
