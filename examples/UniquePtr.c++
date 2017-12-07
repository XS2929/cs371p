// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <memory>     // unique_ptr

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
//  unique_ptr<A> x = new A; // error: no viable conversion from 'A *' to 'unique_ptr<A>'
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    }
    assert(A::c == 0);
    }

    {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
//  unique_ptr<A> y = x;       // error: call to implicitly-deleted copy constructor of 'unique_ptr<A>'
//  unique_ptr<A> y(x);        // error: call to implicitly-deleted copy constructor of 'unique_ptr<A>'
    unique_ptr<A> y = move(x);
    assert(A::c    == 1);
    assert(x.get() == nullptr);
    }
    assert(A::c == 0);
    }

    {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A, default_delete<A>());
    unique_ptr<A> y(new A, default_delete<A>());
    assert(A::c == 2);
//  x = y;                                       // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    assert(A::c    == 1);
    assert(y.get() == nullptr);
    }
    assert(A::c == 0);
    }

    {
    assert(A::c == 0);
    {
    unique_ptr<A, std::function<void (A*)>> x(new A, [] (A* p) -> void {delete p;});
    unique_ptr<A, std::function<void (A*)>> y(new A, [] (A* p) -> void {delete p;});
    assert(A::c == 2);
//  x = y;                                                                           // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    assert(A::c    == 1);
    assert(y.get() == nullptr);
    }
    assert(A::c == 0);
    }}

int main () {
    cout << "UniquePtr.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
