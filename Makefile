all: main sp

main:main.cpp
	$(CXX) main.cpp -o main

sp:SuperPrime_HW.cpp
	$(CXX) SuperPrime_HW.cpp -o sp

check:


distcheck:
