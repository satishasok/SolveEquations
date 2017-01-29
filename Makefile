# the compiler: g++ for C++
CPP_COMPILER = g++

# compiler flags:
CFLAGS  = -std=c++11 -Wall -g

# the build target executable:
BUILD_TARGET = SolveEquations

# build object files
BUILD_OBJS =  SolveEquations.o Equation.o Input.o Output.o EquationSolving.o

# files to delete on clean
REBUILDABLES = $(BUILD_OBJS) $(BUILD_TARGET)

# main target
all: $(BUILD_TARGET)

# build target
$(BUILD_TARGET): $(BUILD_OBJS)
	$(CPP_COMPILER) $(CFLAGS) -o $(BUILD_TARGET) $(BUILD_OBJS)

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o: %.cpp
	$(CPP_COMPILER) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(REBUILDABLES)
