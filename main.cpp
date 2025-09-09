#include <iostream>
#include <chrono>
#include <functional>

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