#include "lab03.h"
#include "svg.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_same()
{
    double min = 0;
    double max = 0;
    find_minmax({2, 2, 2}, min, max);
    assert(min == 2);
    assert(max == 2);
}
void test_one()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void test_homework_1 ()
{
    vector<size_t> bins = {3,4,7,21};
    assert(create_color_column(bins,21,bins[0]) == "999");
    assert(create_color_column(bins,21,bins[1]) == "888");
    assert(create_color_column(bins,21,bins[2]) == "777");
    assert(create_color_column(bins,21,bins[3]) == "111");
}

void test_homework_2 ()
{
    vector<size_t> bins = {1,9,7};
    assert(create_color_column(bins,9,bins[0]) == "999");
    assert(create_color_column(bins,9,bins[1]) == "111");
    assert(create_color_column(bins,9,bins[2]) == "333");
}

void test_homework_3 ()
{
    vector<size_t> bins = {5,6};
    assert(create_color_column(bins,6,bins[0]) == "999");
    assert(create_color_column(bins,6,bins[1]) == "111");
}

int
main()
{
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();

}

