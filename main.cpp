#include <iostream>
#include <chrono>
#include <functional>
#include "fibonacci.hpp"
#include <vector>

template <typename Func, typename... Args>
auto measure_runtime(Func &&func, Args &&...args)
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    
    std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

    auto end = high_resolution_clock::now();
    auto passed = duration_cast<nanoseconds>(end - start).count();

    std::cout << "Time passed: " << passed << " ns" << std::endl;
}

std::vector<std::int8_t> random_generator() 
{
    std::srand(std::time(nullptr)); // seed with current time

    std::vector<std::int8_t> array;
    array.reserve(10);

    for (int i = 0; i < 10; ++i) {
        array.push_back(std::rand() % 100); // random number between 0 and 99
    }

    return array;
}

std::int8_t search_min(std::vector<std::int8_t> array) 
{
    std::int8_t min = array[0];
    
    for(std::int8_t i = 0; i < array.size(); ++i) {
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    
    std::cout << "Given array:  ";
    
    for (int n : array) {
        std::cout << n << " ";
    }

    std::cout << "selected minimum number is " << static_cast<int>(min) << std::endl;

    return min;
}

int main()
{
    std::vector<std::int8_t> array = random_generator();

    measure_runtime(calcualte_fibonacci_with_loop);
    measure_runtime(calcualte_fibonacci_with_recursion, 0, 1, 17);
    measure_runtime(search_min, array);

}