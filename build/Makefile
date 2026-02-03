# Compiler
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iraylib/src

# Library flags (dynamic linking)
LDFLAGS  = -Lraylib/src -lraylib -Wl,-rpath,'$$ORIGIN/raylib/src' -lm -ldl -lpthread -lX11

# Target executable
TARGET   = game

# All .cpp files in src/
SRC      = $(wildcard src/*.cpp)

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean target
clean:
	rm -f $(TARGET)

