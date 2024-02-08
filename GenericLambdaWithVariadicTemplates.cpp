/*
Create a generic lambda function using variadic templates that can concatenate an arbitrary number of strings.
*/
#include <iostream>
#include <string>

int main() {
	std::string str1 = "Hi, ";
	std::string str2 = "everybody";
	const auto lm = [](auto... args) noexcept -> std::string {
		//return (std::string{} + ... + std::move(args));
		//or
		std::string result;
		((result += std::move(args)),...);
		return result;
	};
	
	std::cout << lm(str1,str2) << std::endl;
	std::cout << lm(str1,str2,"!") << std::endl;
	return 0;
}
