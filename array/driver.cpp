#include "array_scratch.h"
#include <iostream>


int main () {

  scratch::array<int, 5> a = {0, 1, 2, 3};
//  scratch::array<int, 5> a;
  a[4] = 4;

  std::cout << a[0] << std::endl;
  std::cout << a[1] << std::endl;
  std::cout << a[2] << std::endl;
  std::cout << a[3] << std::endl;
  std::cout << a[4] << std::endl;

  return 0;
}
