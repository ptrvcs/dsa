#include <iostream>
#include <vector>

#include "fibonacci.hpp"
#include "helper_functions.hpp"

std::int16_t search_min(std::vector<std::int16_t> array)
{
    std::int16_t min = array[0];

    for (std::int16_t j = 0; j < array.size(); ++j)
    {
        if (array[j] < min)
        {
            min = array[j];
        }
    }

    std::cout << "selected minimum number is " << static_cast<int>(min) << std::endl;

    return min;
}

std::vector<std::int16_t> bubble_sorting_algo(std::vector<std::int16_t> array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = 0; j < array.size() - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int n : array)
    {
        std::cout << n << " ";
    }

    return array;
}

int main()
{
    std::vector<std::int16_t> array = random_generator(10000);

    // measure_runtime(calcualte_fibonacci_with_loop);
    // measure_runtime(calcualte_fibonacci_with_recursion, 0, 1, 17);
    // measure_runtime(search_min, array);
    measure_runtime(bubble_sorting_algo, array);
}