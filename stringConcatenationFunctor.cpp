/*
Objective: Create a functor called StringConcatenator that concatenates strings passed to it.
*/
#include <iostream>
#include <string>

class StringConcatenator {
public:
	std::string operator()(std::string str) {
		m_result += str;
		return m_result;
	}
	std::string getStr() const {
		return m_result;
	}
private:
	std::string m_result;
};

int main() {
	StringConcatenator concat;
	concat("I love");
	concat(" C++");
	std::cout << concat.getStr() << std::endl;
	return 0;
}
