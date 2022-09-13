#include <iostream>

struct S
{
	int data {} ;

  S (int number) : data(number) {};

  S (const S & source) : data(source.data) {};

} ;
int main()
{
	S s1 = 123 ;
  S s2 = s1;
	std::cout << s1.data << std::endl;
	std::cout << s2.data << std::endl;
}
