// -----------
// Fri, 22 Sep
// -----------

/*
finished types
l-values / r-values
pre  increment
post increment
*/

int i = 2;
++i;
++2;
cout << (++i);
(++i) = j;

i++;
2++;           // not ok
cout << (i++);
(i++) = j;     // not ok

++++i;

/*
in Java arrays can only be on the heap, always have to say new
in C++  arrays can be on the stack or the heap

in C++/Java, all arrays are fixed-size
in C++, const arrays have unchangeable elements

[] returns an l-value on non-const arrays
[] returns an r-value on     const arrays
*/

/*
two tokens
    *, &
two contexts
    with a typename
    without
*/

int i = 2;
int v = i;
++v;
cout << i; // 2
cout << v; // 3

int* p = i;  // not ok
int* p = &i; // & must take an l-value
++p;         // compile time, but run time undefined
++*p;
++*i; // not ok
++*2; // not ok

int& r = &i; // not ok
int& r = i;
++r;
++*r;        // not ok

/*
Questions
    Can arrays be on the stack in C++ or Java?
    Can arrays be on the heap  in C++ or Java?
    Can arrays change size in C++ or Java?
    Does Java's array index operator return an l-value or r-value
    Does C++'s array index operator return an l-value or r-value
    What's the l-value / r-value behavior of *, &?
*/
