#include <iostream>
#include <vector>
#include <string>
#include "lab03.h"
#include "svg.h"
#include <windows.h>

using namespace std;

DWORD WINAPI GetVersion(void);

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram(vector<double> numbers, size_t count)
{
    vector<size_t> result(count);
    double max, min;
    find_minmax(numbers, min, max);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * count);
        if (bin == count)
        {
            bin--;
        }
        result[bin]++;
    }
    return result;
}

int main()
{
  printf("Version is %x\n", GetVersion());
  printf("Version is %u\n", GetVersion());

    return 0;
}
