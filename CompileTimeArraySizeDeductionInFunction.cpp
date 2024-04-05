#include <iostream>
#include <cstdlib>

template <typename T, std::size_t N>
int linearSearch(const T key, const T (&arr)[N]) {
	for(std::size_t i{0}; i < N; ++i) {
		if(arr[i] == key) { return i; }
	}
	return -1;
}

int main() {
	const int size = 7;
	int arr[size] {2,37,4,1,-5,12,6};
	std::cout << linearSearch(-5,arr) << std::endl;
	return 0;
}
