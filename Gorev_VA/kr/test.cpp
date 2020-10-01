#include <iostream>
#include "intset.h"

int main(void)
{
	intset IS(-2, 2);

	std::cout << IS.is_empty() << "\n";

    IS.put(0);
	IS.put(1);
	IS.put(1);
	IS.put(2);
	IS.put(2);

	IS.del(2);

	intset IS1(IS);

	std::cout << IS.is_empty() << "\n";

    std::cout << "min is " << IS.find_min() << "\n";
    std::cout << "left border is " << IS.left_bord() << "\n";
	return 0;
}