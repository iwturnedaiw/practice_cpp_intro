#include "array_scratch.h"
#include <iostream>


int main () {

  scratch::array<int, 5> a = {0, 1, 2, 3};
//  scratch::array<int, 5> a;
  a[4] = 4;

  std::cout << "a[0]: 0 == " << a[0] << std::endl;
  std::cout << "a[1]: 1 == " << a[1] << std::endl;
  std::cout << "a[2]: 2 == " << a[2] << std::endl;
  std::cout << "a[3]: 3 == " << a[3] << std::endl;
  std::cout << "a[4]: 4 == " << a[4] << std::endl;

  a.fill(100);
  std::cout << "a[0]: 100 == " << a[0] << std::endl;
  std::cout << "a[1]: 100 == " << a[1] << std::endl;
  std::cout << "a[2]: 100 == " << a[2] << std::endl;
  std::cout << "a[3]: 100 == " << a[3] << std::endl;
  std::cout << "a[4]: 100 == " << a[4] << std::endl;

  const scratch::array<int, 3> b = {0, 1, 2};
  std::cout << b[2] << std::endl;
  std::cout << "a size: " << a.size() << std::endl;
  std::cout << "b size: " << b.size() << std::endl;

  
  a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 3; a[4] = 4;

  auto itr = a.begin();
  std::cout << "*itr++: 0 == " << *(itr++) << std::endl;
  std::cout << "*itr  : 1 == " << *itr << std::endl;
  std::cout << "*++itr: 2 == " << *(++itr) << std::endl;
  std::cout << "*itr  : 2 == " << *itr << std::endl;

  auto itr1 = a.end();
  std::cout << "*--itr: 4 == " << *(--itr1) << std::endl;
  std::cout << "*itr--: 4 == " << *(itr1--) << std::endl;
  std::cout << "*itr  : 3 == " << *itr1  << std::endl;

  std::cout << "loop: " << std::endl;
  for (auto itr = a.begin(); itr != a.end(); ++itr) {
    std::cout << *itr << std::endl;
  }


  auto itr2 = a.begin();
  std::cout << "*(itr+3): 3 == " << *(itr2 + 3) << std::endl;
  std::cout << "itr[2]  : 2 == " << itr2[2] << std::endl;
  auto itr3 = a.end();
  std::cout << "*(itr-3): 1 == " << *(itr3 - 3) << std::endl;

  auto b1 = (itr2 < itr3);
  std::cout << "< : 1 == " << b1 << std::endl;
  b1 = (itr2 > itr3);
  std::cout << "> : 0 == " << b1 << std::endl;
  itr2 += 5;
  b1 = (itr2 < itr3);
  std::cout << "< : 0 == " << b1 << std::endl;
  b1 = (itr2 <= itr3);
  std::cout << "<=: 1 == " << b1 << std::endl;
  b1 = (itr3 > itr2);
  std::cout << "> : 0 == " << b1 << std::endl;
  b1 = (itr3 >= itr2);
  std::cout << ">=: 1 == " << b1 << std::endl;

  auto ci = a.cbegin();
  //*ci = -100;
  std::cout << "*itr++: 0 == " << *(ci++) << std::endl;
  std::cout << "*itr  : 1 == " << *ci << std::endl;
  std::cout << "*++itr: 2 == " << *(++ci) << std::endl;
  std::cout << "*itr  : 2 == " << *ci << std::endl;

  auto cie = a.cend();
  std::cout << "*--itr: 4 == " << *(--cie) << std::endl;
  std::cout << "*itr--: 4 == " << *(cie--) << std::endl;
  std::cout << "*itr  : 3 == " << *cie  << std::endl;

  std::cout << "loop: " << std::endl;
  for (auto itr = a.cbegin(); itr != a.cend(); ++itr) {
    std::cout << *itr << std::endl;
  }

  auto citr2 = a.cbegin();
  std::cout << "*(itr+3): 3 == " << *(citr2 + 3) << std::endl;
  std::cout << "itr[2]  : 2 == " << citr2[2] << std::endl;
  auto citr3 = a.cend();
  std::cout << "*(itr-3): 1 == " << *(citr3 - 3) << std::endl;

  auto cb1 = (citr2 < citr3);
  std::cout << "< : 1 == " << cb1 << std::endl;
  cb1 = (citr2 > citr3);
  std::cout << "> : 0 == " << cb1 << std::endl;
  citr2 += 5;
  cb1 = (citr2 < citr3);
  std::cout << "< : 0 == " << cb1 << std::endl;
  cb1 = (citr2 <= citr3);
  std::cout << "<=: 1 == " << cb1 << std::endl;
  cb1 = (citr3 > citr2);
  std::cout << "> : 0 == " << cb1 << std::endl;
  cb1 = (citr3 >= citr2);
  std::cout << ">=: 1 == " << cb1 << std::endl;

  return 0;
}
