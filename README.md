# SolveEquations
Takes in an input of linear algebraic equations and solves them.

Example Input:
offset = 4 + random + 1
location = 1 + origin + offset
origin = 3 + 5
random = 2

Expected output: (sorted by the LHS variable name)
location = 16
offset = 7
origin = 8
random = 2

How To Build:
* clone the repo
* in the shell, cd to the repo folder
* call > make clean
* call > make all
* Run commands:
> ./SolveEquations Input1.txt

Output should look like this:
location = 16
offset = 7
origin = 8
random = 2

> ./SolveEquations Input2.txt
> ./SolveEquations Input3.txt
