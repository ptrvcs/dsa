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
    duration<double> passed = end - start;

    std::cout << "Time passed: " << passed.count() << " sec" << std::endl;
}

std::vector<std::int16_t> random_generator(int size)
{
    std::srand(std::time(nullptr)); // seed with current time

    std::vector<std::int16_t> array;
    array.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        array.push_back(std::rand() % 100); // random number between 0 and 99
    }

    return array;
}

void printArray(std::vector<std::int16_t> array)
{
    #ifdef VERBOSE
        for(int value : array)
        {
            std::cout << value << ",";
        }
    #endif
}