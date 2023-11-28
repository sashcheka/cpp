#include <cstddef>
#include <iostream>

struct Vector3 {
	float x, y, z;
};

int main() {
	int offsetX = (int)&((Vector3*)nullptr)->x;
	std::cout << offsetX << std::endl;

	int offsetY = (int)&((Vector3*)nullptr)->y;
	std::cout << offsetY << std::endl;

	int offsetZ = (int)&((Vector3*)nullptr)->z;
	std::cout << offsetZ << std::endl;

	std::cin.get();
}