main:main.cpp
	$(CXX) main.cpp -o main

check:
	cppcheck main.cpp

distcheck:
