# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRC = main.cpp matrix.cpp

# Header files
HEADERS = matrix.hpp

# Output executable
TARGET = matrix_program

# Default rule
all: $(TARGET)

# Compile the executable
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)
