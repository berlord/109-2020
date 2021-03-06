#include <string>
#include <iostream>
#include "clock.h"

int main(void)
{
    Clock C(2, 0);
    C = nextClock(C);

    for (int k = 0; k < 10; k++)
    {
        Clock temp = C;
        temp = C = temp;
        temp = temp;
        temp = C;
    }

    try
    {
        nextClock(nextClock(C), C);
    }
    catch (ClockError &err)
    {
        std::cout << "EXEPTION: " << err.get_reason() << "\n";
    }

    return 0;
}