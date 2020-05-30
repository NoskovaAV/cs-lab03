#ifndef LAB03_H_INCLUDED
#define LAB03_H_INCLUDED
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
struct Input
{
    vector<double> numbers;
    size_t bin_count;
};
struct Option
{
    bool txt;
    bool svg;
    bool help;
    char *url;
};
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const Input&data);
string information_system();
#endif // LAB03_H_INCLUDED
