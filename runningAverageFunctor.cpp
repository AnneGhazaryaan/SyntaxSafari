/*
Objective: Create a functor called RunningAverage that calculates the running average of values passed to it.
*/
#include <iostream>

class RunningAverage {
public:
	RunningAverage() : m_counter{}, m_currentSum{} {}
	int operator()(int value) {
		++m_counter;
		m_currentSum += value;
		return m_currentSum / m_counter;
	}
private:
	int m_counter;
	int m_currentSum;
};

int main() {
	RunningAverage r;
	std::cout << r(5) << std::endl;
	std::cout << r(7) << std::endl;
	std::cout << r(3) << std::endl;
	return 0;
}
