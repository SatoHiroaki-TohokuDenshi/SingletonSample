#include <iostream>
#include "Singleton.h"

class Sample {
public:
	Sample() { std::cout << "new Sample()" << std::endl; };
	~Sample() { std::cout << "delete Sample()" << std::endl; };

private:

};

int main() {
	std::cout << "Hello, C++" << std::endl;
	auto sample = Singleton<Sample>::GetInstance();

	return 0;
}
