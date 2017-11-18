// -------------
// Factorial.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

int factorial (int n) {
    assert(n >= 0);
    if (n < 2)
        return 1;
    return n * factorial(n - 1);}

void test () {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(4) == 24);
    assert(factorial(5) == 120);}

int main () {
    cout << "Factorial.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
