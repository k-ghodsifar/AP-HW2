CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o map.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
q1.o: q1.cpp
	$(CXX) $(CXXFLAGS) q1.cpp
map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) map.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
