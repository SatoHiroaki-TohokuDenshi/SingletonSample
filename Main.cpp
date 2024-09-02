#include <iostream>
#include "Singleton.h"

class Sample {
public:
	Sample() { std::cout << "new Sample()" << std::endl; };
	Sample(int a) { std::cout << "new Sample(int)" << std::endl; };
	Sample(int a, int b) { std::cout << "new Sample(int, int)" << std::endl; };
	~Sample() { std::cout << "delete Sample()" << std::endl; };

private:

};

int main() {
	std::cout << "Hello, C++" << std::endl;
	auto sample = Singleton<Sample>::GetInstance();

	return 0;
}
