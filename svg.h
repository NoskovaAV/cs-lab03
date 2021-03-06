#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>

using namespace std;
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, size_t text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
size_t find_max_column(const vector<size_t>& bins);
size_t find_min_column(const vector<size_t>& bins);
string create_color_column(const vector<size_t>& bins, size_t max_count, size_t bin);
void show_histogram_svg(const vector<size_t>& bins);

#endif // SVG_H_INCLUDED
