
#include "text.h"
//#include <iostream>

int main()
{
	ZZ a1(1,3), a2(1,3), a3(1,3), b1(2,3), b2(2,3), b3(2,3);
	a1.name(1);
	a2.name(2);
	a3.name(3);
	b1.name(1);
	b2.name(2);
	b3.name(3);
	b2.print();
	a2.message(b2);
	b2.print();
	/*a1.print();
	a2.print();
	a3.print();
	b2.print();
	*/
	
	return 0;
}
