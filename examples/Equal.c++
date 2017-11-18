// ---------
// Equal.c++
// ---------

// http://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

void test () {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};

    assert(!equal(a, a + 3, b));
    assert( equal(a, a + 3, b + 1));}

int main () {
    cout << "Equal.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
