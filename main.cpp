#include <iostream>
#include <chrono>

int calcualte_fibonacci_with_loop()
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



int main()
{
    using namespace std::chrono;

    auto start_loop = high_resolution_clock::now();
    calcualte_fibonacci_with_loop();
    auto end_loop = high_resolution_clock::now();
    auto passed_loop = duration_cast<nanoseconds>(end_loop - start_loop).count();
    std::cout << "Loop time: " << passed_loop << " ns" << std::endl;
    
    std::cout << "-----" << std::endl;

    auto start_rec = high_resolution_clock::now();
    calcualte_fibonacci_with_recursion(0, 1, 17);
    auto end_rec = high_resolution_clock::now();
    auto passed_rec = duration_cast<nanoseconds>(end_loop - start_loop).count();
    std::cout << "Loop time: " << passed_rec << " ns" << std::endl;

}