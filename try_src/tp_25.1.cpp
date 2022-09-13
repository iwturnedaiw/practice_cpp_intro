#include <iostream>

struct S
{
	int data {} ;
	// *this はメンバー関数が呼ばれたS のオブジェクト
	S & THIS() { return *this ; }
} ;
int main()
{
	S s1 ;
	s1.THIS().data = 123 ;
	// 123
	std::cout << s1.data ;
	S s2 ;
	s2.THIS().data = 456 ;
	// 456
	std::cout << s2.data ;
}
