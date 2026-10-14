CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2
TARGET   := factorizer
SRCS     := main.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild
