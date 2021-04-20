all: main sp

main:main.cpp
	$(CXX) main.cpp -o main

sp:SuperPrime_HW.cpp
	$(CXX) SuperPrime_HW.cpp -o sp
	$(CXX) SuperPrime_HW2.cpp -o sp

check:


distcheck:
