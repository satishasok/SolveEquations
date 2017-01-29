#include "Output.h"

void OutputSolvedEquations(const std::map<std::string, int>& solvedEquations)
{
	// The map is actually a tree, and is sorted by KEY order.
        // so just iterating thru the maps and printing key/value will print with Key sorted alphabhetically.
        for (auto& kv : solvedEquations) {
                std::cout << kv.first << " = " << kv.second << std::endl;
        }
}
