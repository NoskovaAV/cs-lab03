#include "svg.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream> // for stringsteam

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, size_t text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

size_t find_max_column(const vector<size_t>& bins)
{
    size_t max_column = bins[0];
    for (size_t bin : bins)
    {
        if (max_column<bin)
            max_column=bin;
    }
    return max_column;
}
size_t find_min_column(const vector<size_t>& bins)
{
    size_t min_column = bins[0];
    for (size_t bin : bins)
    {
        if (min_column<bin)
            min_column=bin;
    }
    return min_column;
}
string create_color_column(const vector<size_t>& bins, size_t max_count, size_t bin)
{
    size_t max = find_max_column(bins);
    size_t min = find_min_column(bins);
    size_t color;
    if (bin == max)
    {
        color = 111;
    }
    else if (bin == min)
    {
        color = 999;
    }
    else
    {
        color = (10 - (bin * 9) / max_count)*111;
    }
    ostringstream c;
    c << color;
    string color_column = c.str();
    return color_column;
}

void show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const size_t MAX_ASTERISK = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    double top = 0;
    size_t max_count = 0;

    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }

    const bool scaling_needed = max_count > MAX_ASTERISK;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    for (size_t bin : bins)
    {

        string color_column = create_color_column(bins, max_count, bin);

        cout << color_column << endl;

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        const double bin_width = BLOCK_WIDTH * height;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, bin);
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "white", "#" + color_column);
        top += BIN_HEIGHT;
    }
    svg_end();
}
