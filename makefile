# compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = hello

# Source files
SRCDIR = src
SRCS = $(SRCDIR)/main.cpp

# Header files
INCDIR = include
INCLUDES = -I$(INCDIR)

# Build target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Clean target
Clean:
	rm -f $(TARGET)

