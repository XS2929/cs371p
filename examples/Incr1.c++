// ---------
// Incr1.c++
// ---------

// http://en.cppreference.com/w/cpp/language/operator_incdec

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

int& pre_incr (int& r) {
    return r += 1;}

int post_incr (int& r) {
    int v = r;
    r += 1;
    return v;}

int main () {
    cout << "Incr1.c++" << endl;

    {
    int i = 2;
    int j = pre_incr(i);
    assert(i == 3);
    assert(j == 3);
    }

    {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    assert(i == 4);
    assert(j == 4);
    }

    {
    int i = 2;
    int j = post_incr(i);
    assert(i == 3);
    assert(j == 2);
    }

    {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    assert(i == 2);
    }

    cout << "Done." << endl;
    return 0;}
