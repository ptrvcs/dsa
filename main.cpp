#include <iostream>
#include <vector>

#include "fibonacci.hpp"
#include "helper_functions.hpp"

std::int8_t search_min(std::vector<std::int8_t> array)
{
    std::int8_t min = array[0];

    for (std::int8_t i = 0; i < array.size(); ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    std::cout << "Given array:  ";

    for (int n : array)
    {
        std::cout << n << " ";
    }

    std::cout << "selected minimum number is " << static_cast<int>(min) << std::endl;

    return min;
}

void bubble_sorting_algo(std::vector<std::int8_t> array)
{
    // auto first_element = array[0];
    // auto second_element = array[1];

    for (int i = 0; i < array.size() - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            auto temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}

int main()
{
    std::vector<std::int8_t> array = random_generator();

    measure_runtime(calcualte_fibonacci_with_loop);
    measure_runtime(calcualte_fibonacci_with_recursion, 0, 1, 17);
    measure_runtime(search_min, array);
    bubble_sorting_algo(array);
}