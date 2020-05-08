#ifndef LAB03_H_INCLUDED
#define LAB03_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;
struct Input
{
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const Input&data);
#endif // LAB03_H_INCLUDED
