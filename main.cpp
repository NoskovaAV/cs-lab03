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
    DWORD mask = 0x0000ffff;
    DWORD mask_major = 0b00000000'00000000'00000000'11111111;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    printf("Windows (10) version is %u.\n", version);
    printf("Windows (16) version is %x.\n", version);
    printf("Platform is %u.\n", platform);
    printf("Windows major version is %u.\n", version_major);
    printf("Windows minor version is %u.\n", version_minor);
    if ((info & 0x40000000) == 0)
    {
        DWORD build = platform;
        printf("Windows build is %u.\n", build);
    }
    printf("Windows v%u.%u (build %u)\n",version_major,version_minor,platform);

    return 0;
}
