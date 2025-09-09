#include <iostream>
#include <chrono>
#include <functional>
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

    for (int i = 0; i < 10; ++i)
    {
        array.push_back(std::rand() % 100); // random number between 0 and 99
    }

    return array;
}