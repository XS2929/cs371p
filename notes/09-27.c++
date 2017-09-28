// -----------
// Wed, 27 Sep
// -----------

/*
variables
arguments

equal()
*/

struct A {};

int main () {
    A x;           // default constructor
    A y = x;       // copy constructor
    A y(x);
    y = x;         // copy assignment
    cout (x == y); // not ok
    }              // destructor

// a has to have at least 15 elements
// b has to have at least 25 elements
equal(a + 10, a + 15, b + 20);

template <typename T1, typename T2>
bool equal (T1* b, T1* e, T2* x) {
    while (b < e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

int a[] = {...};
int b[] = {...};
equal(a + 10, a + 15, b + 20); // T1 -> int; T2 -> int

list<int> x(...);
vector<int> y(...);
list<int>::iterator   b = x.begin();
list<int>::iteraror   e = x.end();
vector<int>::iterator p = y.begin();
equal(b, e, p);                      // not ok

template <typename T1, typename T2>
bool equal (T1 b, T1 e, T2 x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

int a[] = {...};
int b[] = {...};
equal(a + 10, a + 15, b + 20); // T1 -> int*; T2 -> int*

list<int> x(...);
vector<int> y(...);
list<int>::iterator   b = x.begin();
list<int>::iteraror   e = x.end();
vector<int>::iterator p = y.begin();
equal(b, e, p);                      // T1 -> list<int>::iterator; T2 -> vector<int>::iterator

/*
Questions
    What are the four automatically-generated methods of a class?
    Why doesn't the first implementation of equal() work with list or vector?
    Why can't the second implementation of equal() use the < operator?
*/
