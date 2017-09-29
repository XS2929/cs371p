// -----------
// Fri, 29 Sep
// -----------

/*
equal()
consts
*/

/*
iterators are like a glue between
containers
algorithms
*/

/*
OO languages turn runtime errors into compile time errors
*/

/*
Java

define sort on List (an interface, includes get())

ArrayList  implements List, get() is O(1)
LinkedList implements List, get() is O(n)

sort(ArrayList):  O(n   log n)
sort(LinkedList): O(n^2 log n)
*/

/*
C++
sort(a begin iterator, an end iterator)
sort(on begin and end of a vector) : O(n log n)
sort(on begin and end of a list)   : doesn't compile
*/

/*
OO languages turn runtime errors into compile time errors
consts
*/

int i;
i = 2;

const int ci;     // not ok, must be initialized
const int ci = 3;

++i;
++ci; // not ok

/*
read write, many location
*/
int       i  = 2;
const int ci = 3;

int* p;

p = &i;
++*p;
cout << i; 3

p = &ci; // not ok
++*p;

/*
read only, many location
*/

int       i  = 2;
const int ci = 3;

const int* pc;
pc = &ci;
++*pc;         // not ok

pc = &i;
++*pc;         // not ok

cout << *pc;   // 2
++i;
cout << *pc;   // 3

/*
read write, one location
*/

int       i  = 2;
const int ci = 3;

int* const cq;       // not ok
int* const cq = &ci; // not ok
int* const cq = &i;

++cq;      // not ok
++*cq;
cout << i; // 3

int s;
cin >> s;

int a[s]; // not ok

int* a = new int[s]; // on the heap
++a;
delete [] a; // runtime error

int* const a = new int[s]; // on the heap
++a;                       // compile time error
delete [] a;

/*
read only, one location
*/

int       i  = 2;
const int ci = 3;

const int* const cpc;       // not ok
const int* const cpc = &ci;
const int* const cpc = &i;
++cpc; // not ok
++*cpc; // not ok

/*
Questions
    Describe the four kinds of pointers:
        T*
        const T*
        T* const
        const T* const
*/
