// -------------
// SharedPtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>   // assert
#include <algorithm> // swap
#include <iostream>  // cout, endl
#include <memory>    // default_delete

using namespace std;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

void test () {
    {
    assert(A::c == 0);
    {
//  shared_ptr<A> x = new A;   // error: no viable conversion from 'A *' to 'shared_ptr<A>'
    shared_ptr<A> x(new A);
    assert(x.use_count() == 1);
    assert(A::c == 1);
    }
    assert(A::c == 0);
    }

    {
    assert(A::c == 0);
    {
    shared_ptr<A> x(new A);
    shared_ptr<A> y = x;
    assert(x.use_count() == 2);
    assert(y.use_count() == 2);
    assert(A::c == 1);
    assert(x.get() == y.get());
    }
    assert(A::c == 0);
    }

    {
    assert(A::c == 0);
    {
    shared_ptr<A> x(new A, [] (A* p) {delete p;});
    shared_ptr<A> y(new A, default_delete<A>());
    assert(A::c == 2);
    assert(x.get() != y.get());
    x = y;
    assert(x.use_count() == 2);
    assert(y.use_count() == 2);
    assert(A::c == 1);
    assert(x.get() == y.get());
    }
    assert(A::c == 0);
    }}

int main () {
    cout << "SharedPtr.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
