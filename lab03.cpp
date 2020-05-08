#pragma once
#include <vector>
#include <iostream>
#include <vector>
#include "lab03.h"

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (numbers.size()!=0)
    {
        min = numbers[0];
        max = numbers[0];
        for(double number: numbers)
        {
            if(min>number)
                min=number;
            if(max<number)
                max=number;
        }
    }
}

vector<size_t> make_histogram(const Input&data)
{
    vector<size_t> result(data.bin_count);
    double max, min;
    find_minmax(data.numbers, min, max);
    for (double number : data.numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * data.bin_count);
        if (bin == data.bin_count)
        {
            bin--;
        }
        result[bin]++;
    }
    return result;
}


