#include <iostream>
#include <Vector.hpp>

int main() {
  mds::Vector<int> array_1(10);
  mds::Vector<int> array_2(10, 0);
  mds::Vector<int> array_3 = array_1;
  mds::Vector<int> array_4 = std::move(array_1);

  std::cout << "Success?";
}