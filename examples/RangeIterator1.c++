// ------------------
// RangeIterator1.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
class RangeIterator {
    friend bool operator == (const RangeIterator& lhs, const RangeIterator& rhs) {
        return (lhs._v == rhs._v);}

    friend bool operator != (const RangeIterator& lhs, const RangeIterator& rhs) {
        return !(lhs == rhs);}

    private:
        T _v;

    public:
        RangeIterator (const T& v) :
                _v (v)
            {}

        T operator * () const {
            return _v;}

        RangeIterator& operator ++ () {
            ++_v;
            return *this;}

        RangeIterator operator ++ (int) {
            RangeIterator x = *this;
            ++*this;
            return x;}};

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

void test () {
    {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    assert(b == e);
    }

    {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    assert(b  != e);
    assert(*b == 2);
    RangeIterator<int>& x = ++b;
    assert(&x == &b);
    assert(b  == e);
    }

    {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    assert(b  != e);
    assert(*b == 2);
    ++b;
    assert(b  != e);
    assert(*b == 3);
    RangeIterator<int> x = b++;
    assert(&x != &b);
    assert(b  == e);
    }

    {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    const int a[] = {2, 3, 4};
    assert(my_equal(b, e, a));
    }}

int main () {
    cout << "RangeIterator1.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
