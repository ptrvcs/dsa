#include <iostream>
#include <vector>

#include "fibonacci.hpp"
#include "helper_functions.hpp"
#include "sorting_algos.hpp"



int main()
{
    std::vector<std::int16_t> array = random_generator(10000);

    // measure_runtime(calcualte_fibonacci_with_loop);
    // measure_runtime(calcualte_fibonacci_with_recursion, 0, 1, 17);
    // measure_runtime(search_min, array);
    printArray(array);
    measure_runtime(bubble_sorting_algo, array);
    printArray(array);
    measure_runtime(quickSort, array, 0, array.size() - 1);
    printArray(array);

}