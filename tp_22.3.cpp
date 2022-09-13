struct array_int_3 { int storage [3] ; } ;
int main()
{
	array_int_3 a = { 0,1,2 } ;
	array_int_3 b = a ;
	// b.storage[0] == a.storage[0]
	// b.storage[1] == a.storage[1]
	// b.storage[2] == a.storage[2]
}
