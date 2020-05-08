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


int main(int argc,char* argv[])
{
    curl_global_init(CURL_GLOBAL_ALL);
    if (argc>1)
    {
        CURL * curl = curl_easy_init ();
        if (curl)
        {
            CURLcode res;
            curl_easy_setopt (curl, CURLOPT_URL, argv[1]);
            res = curl_easy_perform (curl);
            res = CURLE_FAILED_INIT;
            if (res != CURLE_OK)
            {
                cout << curl_easy_strerror(res);
                exit (1);
            }
            curl_easy_cleanup (curl);
        }
        return 0;
    }

    Input data = read_input(cin,true);

    const auto bins = make_histogram(data);

    show_histogram_svg(bins);

    return 0;
}
