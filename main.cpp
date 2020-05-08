#include <iostream>
#include <vector>
#include <string>
#include "lab03.h"
#include "svg.h"
#include <curl/curl.h>

using namespace std;

vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i=0; i<count; i++)
    in >> result[i];

    return result;

}

Input read_input(istream& in,bool promt)
{
    Input data;

    size_t number_count;

if (promt)
{
    cerr << "Enter number count: ";
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter column count: ";
    in >> data.bin_count;
}
else
{
    in >> number_count;
    data.numbers = input_numbers(in,number_count);
    in >> data.bin_count;
}
    return data;
}


int main()
{ curl_global_init(CURL_GLOBAL_ALL);

    Input data = read_input(cin,true);

    const auto bins = make_histogram(data);

    show_histogram_svg(bins);

    return 0;
}
