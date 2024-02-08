#include <iostream>
#include <algorithm>
#include <vector>

class Point {
public:
	Point() : _x{} {}
	Point(int x) : _x{x} {}
	void setX(int x) { _x = x; }
	int getX() const { return _x; }
private:
	int _x;
};

int main() {
	std::vector<Point> abc = {{2},{3},{4}};
	std::sort(abc.begin(), abc.end(), [](const Point& p1, const Point& p2) { return p1.getX() > p2.getX();});
	std::for_each(abc.begin(), abc.end(),[](const Point& p){std::cout << p.getX() << " "; });
	std::cout << std::endl;
	return 0;
}
