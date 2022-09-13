#include <iostream>


void f( const int & )
{
  std::cout << "lvalue\n" ;
}
void f( int && )
{
  std::cout << "rvalue\n" ;
}
int main()
{
  int object { } ;
  f( object ) ; // lvalue
  f( object + object ) ; // rvalue
  f( [=]{ return object ; }() ) ; // rvalue
  f( std::move(object) ) ; // rvalue
}
