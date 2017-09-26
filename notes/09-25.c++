// -----------
// Mon, 25 Sep
// -----------

/*
Incr
operators
arrays
*
&

variables
arguments
*/

struct Foo {};

Foo x;
Foo y = x;

/*
good typed OO languages turn certain runtime errors into compile time errors
*/

void f (int v) {
    ++v;}

int main () {
    int i = 2;
    f(i);
    cout << i;} // 2

void f (int* p) {
    ++p;   // legal, in this case not useful
    ++*p;}

int main () {
    int i = 2;
    f(i);       // not ok
    f(&i);
    f(185);     // not ok
    f(0);       // ok, but leads to a runtime error
    cout << i;} // 3

void f (int& r) { // demands an l-value
    ++*r;         // not ok
    ++r;}

int main () {
    int i = 2;
    f(&i);      // not ok
    f(i);
    f(185);     // not ok
    f(0);       // not ok
    cout << i;} // 3
