TARGET = text
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I../src
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = $(wildcard ../src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) copy_data

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Nowa reguła kopiująca plik danych
copy_data:
	cp ../src/data.txt .

../src/%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f ../src/*.o $(TARGET) data.txt

run: all
	./$(TARGET)

