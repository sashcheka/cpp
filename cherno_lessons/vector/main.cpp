#include <iostream>
#include <ostream>
#include <vector>

struct Vertex {
  float x, y, z;

  Vertex(float x, float y, float z)
    : x(x), y(y), z(z) {}

  Vertex(const Vertex& vertex)
    : x(vertex.x), y(vertex.y), z(vertex.z) {
    std::cout << "copied!" << std::endl;
  }
};

int main() {
  std::vector<Vertex> vertices;
  vertices.reserve(3);
  
  Vertex v(4, 5, 6);
  
  vertices.emplace_back( 1, 2, 3 ); // Use emplace_back when you want to construct an object directly within the vector
  vertices.push_back(v); // Use push_back when you already have an object and want to add it to the vector.

  std::cin.get();
}