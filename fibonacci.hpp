#include <iostream>

void calcualte_fibonacci_with_loop()
{
    int last_before_number = 0;
    int last_number = 1;

    for (int i = 0; i < 17; i++)
    {
        int result = last_before_number + last_number;
        std::cout << result << std::endl;
        last_before_number = last_number;
        last_number = result;
    }
}

void calcualte_fibonacci_with_recursion(int last_before_number, int last_number, int remaining)
{
    if (remaining == 0)
        return;

    int result = last_before_number + last_number;
    std::cout << result << std::endl;
    last_before_number = last_number;
    last_number = result;
    calcualte_fibonacci_with_recursion(last_before_number, last_number, remaining - 1);
}