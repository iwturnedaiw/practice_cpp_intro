#include <iostream>
inline namespace hoge {
	int hoge_f;
}


namespace hoge_ = hoge;


int main() {

  std::cout << hoge_f << std::endl;
  hoge_f++;
  std::cout << hoge::hoge_f << std::endl;
  hoge::hoge_f++;
  std::cout << hoge_::hoge_f << std::endl;
  hoge_::hoge_f++;
  std::cout << hoge_::hoge_f << std::endl;

}

