#include <iostream>
#include <vector>

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

    return array;
}

std::int16_t partition(std::vector<std::int16_t> &array, std::int16_t start, std::int16_t end)
{
    std::int16_t pivot = array[end];
    std::int16_t i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            std::int16_t temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    std::int16_t temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;
}

void quickSort(std::vector<std::int16_t> &array, std::int16_t start, std::int16_t end)
{
    if (end <= start)
        return;

    std::int16_t pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}