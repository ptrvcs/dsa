#include <iostream>
#include <chrono>
#include <functional>
#include "fibonacci.hpp"

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

int main()
{

    measure_runtime(calcualte_fibonacci_with_loop);
    measure_runtime(calcualte_fibonacci_with_recursion, 0, 1, 17);
}