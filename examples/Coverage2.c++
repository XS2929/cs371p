// -------------
// Coverage2.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(2, cycle_length(2));}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall Coverage2.c++ -o Coverage2 -lgtest -lgtest_main -pthread



% Coverage2
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov -b Coverage2.c++ | grep -A 5 "File './Coverage2.h'"
File './Coverage2.h'
Lines executed:88.89% of 9
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
No calls
./Coverage2.h:creating 'Coverage2.h.gcov'
*/
