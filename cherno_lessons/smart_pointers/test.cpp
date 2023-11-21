#include <iostream>
#include <memory>

int main () {
  std::shared_ptr<int> sp1,sp2;
  std::weak_ptr<int> wp;
  sp1 = std::make_shared<int> (20);
  wp = sp1;

  sp2 = wp.lock();
  sp1.reset();

  sp1 = wp.lock();

  std::cout << "*sp1: " << *sp1 << '\n';
  std::cout << "*sp2: " << *sp2 << '\n';

  return 0;
}