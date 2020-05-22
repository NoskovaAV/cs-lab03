#include <iostream>
#include <vector>
#include <string>
#include "lab03.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <windows.h>

using namespace std;

vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i=0; i<count; i++)
    in >> result[i];

    return result;

}
void show_histogram_text(vector<size_t>bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";
        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }
        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
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

size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx)
{
   size_t data_size = item_size*item_count;
   stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    char* item = reinterpret_cast<char*>(items);
    buffer->write(item, data_size);
    return data_size;
}

Input download(const string& address) {

    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);

        CURL * curl = curl_easy_init ();
        if (curl)
        {
            CURLcode res;
            curl_easy_setopt (curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            res = curl_easy_perform (curl);

            if (res != CURLE_OK)
            {
                cout << curl_easy_strerror(res);
                exit (1);
            }
            curl_easy_cleanup (curl);
        }

    return read_input(buffer, false);
}

int main(int argc, char* argv[]) {
    Input input;
    if (argc > 1)
    {
        input = download(argv[1]);
    } else
    {
        input = read_input(cin, true);
    }
        const auto bins = make_histogram(input);

    show_histogram_svg(bins);

    return 0;
}
