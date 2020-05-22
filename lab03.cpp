#pragma once
#include <vector>
#include <iostream>
#include <vector>
#include "lab03.h"
#include <windows.h>
#include <sstream>
#include <string>

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
string information_system()
{
    stringstream buffer;
    DWORD mask = 0x0000ffff;
    DWORD mask_major = 0b00000000'00000000'00000000'11111111;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;

    if ((info & 0x40000000) == 0)
    {
        DWORD build = platform;
        buffer << "Windows:" << version_major << "." << version_minor << " (build" << build << ")\n";
    }

    char get_computer_name[MAX_COMPUTERNAME_LENGTH+1];
    DWORD size = sizeof(get_computer_name);
    GetComputerNameA(get_computer_name, &size);
    buffer << "Computer name:" << get_computer_name << "\n";
    return buffer.str();

}
