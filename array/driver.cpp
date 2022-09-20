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

  a.fill(100);
  std::cout << a[0] << std::endl;
  std::cout << a[1] << std::endl;
  std::cout << a[2] << std::endl;
  std::cout << a[3] << std::endl;
  std::cout << a[4] << std::endl;

  const scratch::array<int, 3> b = {0, 1, 2};
  std::cout << b[2] << std::endl;
  std::cout << "a size: " << a.size() << std::endl;
  std::cout << "b size: " << b.size() << std::endl;

  
  a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 3; a[4] = 4;

  auto itr = a.begin();
  std::cout << *(itr++) << std::endl;
  std::cout << *itr << std::endl;
  std::cout << *(++itr) << std::endl;
  std::cout << *itr << std::endl;

  auto itr1 = a.end();
  std::cout << *(--itr1) << std::endl;
  std::cout << *(itr1--) << std::endl;
  std::cout << *itr1 << std::endl;

  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
  

  return 0;
}
