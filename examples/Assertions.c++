// --------------
// Assertions.c++
// --------------

// http://en.cppreference.com/w/cpp/error/assert

#include <cassert>  // assert
#include <iostream> // cout, endl

int cycle_length_1 (int n) {
    assert(n > 0);
    int c;
    if (n == 1)
        c = 1;
    else if ((n % 2) == 0)
        c = 1 + cycle_length_1(n / 2);
    else
        c = 1 + cycle_length_1((3 * n) + 1);
    assert(c > 0);
    return c;}

int cycle_length__2 (int m, int n) {
    assert(n > 0);
    int c;
    if (n == 1)
        c = m;
    else if ((n % 2) == 0)
        c = cycle_length__2(m + 1, n / 2);
    else
        c = cycle_length__2(m + 1, (3 * n) + 1);
    assert(c > 0);
    return c;}

int cycle_length_2 (int n) {
    return cycle_length__2(1, n);}

int cycle_length_3 (int n) {
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

int main () {
    using namespace std;
    cout << "Assertions.c++" << endl;

    assert(cycle_length_1( 1) == 1);
    assert(cycle_length_1( 5) == 6);
    assert(cycle_length_1(10) == 7);

    assert(cycle_length_2( 1) == 1);
    assert(cycle_length_2( 5) == 6);
    assert(cycle_length_2(10) == 7);

    assert(cycle_length_2( 1) == 1);
    assert(cycle_length_2( 5) == 6);
    assert(cycle_length_2(10) == 7);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -pedantic -std=c++14 -Wall -Weffc++ Assertions.c++ -o Assertions
% Assertions
Assertions.c++
Assertions.app: Assertions.c++:19: int cycle_length_1(int): Assertion `c > 0' failed.



% g++ -pedantic -std=c++14 -DNDEBUG -Wall -Weffc++ Assertions.c++ -o Assertions
% Assertions
Assertions.c++
Done.
*/
