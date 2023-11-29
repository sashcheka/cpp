#include <iostream>
#include <ostream>
#include <vector>

class Vertex {
public:
  float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
  stream << vertex.x << vertex.y << vertex.z << std::endl;
  return stream;
}

int main() {
  std::vector<Vertex*> vertices;
  
  vertices.push_back(new Vertex{ 1, 2, 3 });
  vertices.push_back(new Vertex{ 4, 5, 6 });
  vertices.push_back(new Vertex{ 7, 8, 9 });
  
  for (Vertex* v : vertices) {
    std::cout << *v;
    delete v;
  }
  
  std::cin.get();
}