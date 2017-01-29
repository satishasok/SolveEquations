# SolveEquations
Takes in an input of linear algebraic equations and solves them.

Example Input:
<br>offset = 4 + random + 1
<br>location = 1 + origin + offset
<br>origin = 3 + 5
<br>random = 2

Expected output: (sorted by the LHS variable name)
<br>location = 16
<br>offset = 7
<br>origin = 8
<br>random = 2

How To Build:
* clone the repo
* in the shell, cd to the repo folder
* call > make clean
* call > make all
* Run commands:
> ./SolveEquations Input1.txt

Output should look like this:
<br>location = 16
<br>offset = 7
<br>origin = 8
<br>random = 2

> ./SolveEquations Input2.txt
<br>> ./SolveEquations Input3.txt
