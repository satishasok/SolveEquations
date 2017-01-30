#include "Output.h"

// Iterates thru solvedEquations (map) and prints the Key (LHS) and value (RHS) to stdout.
void OutputSolvedEquations(const std::map<std::string, int>& solvedEquations)
{
	// The map is actually a tree, and is sorted by KEY order.
        // so just iterating thru the maps and printing key/value will print with Key sorted alphabhetically.
        for (auto& kv : solvedEquations) {
                std::cout << kv.first << " = " << kv.second << std::endl;
        }
}
