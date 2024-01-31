/*
Objective:Create a functor called Accumulator that acts as a simple accumulator. It should have an internal counter that increases with each call.
*/
#include <iostream>

class Accumulator {
public:
	Accumulator() : m_eax{} {}
	int operator()(int value) {
		m_eax += value;
		return m_eax;	
	}
private:
	int m_eax;
};

int main() {
	Accumulator a;
	std::cout << a(3) << std::endl;
	std::cout << a(5) << std::endl;
	return 0;
}
