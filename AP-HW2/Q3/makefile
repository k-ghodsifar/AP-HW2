CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q3.o old.o
TARGET = q3


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
q3.o: q3.cpp
	$(CXX) $(CXXFLAGS) q3.cpp
old.o: old.cpp old.h
	$(CXX) $(CXXFLAGS) old.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
