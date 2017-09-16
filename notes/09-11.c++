// -----------
// Mon, 11 Sep
// -----------

/*
Piazza
    blog posts
    pay attention to my responses

Docker
    vim

unit testing with Google Test
coverage with gcov
Collatz optimizations

exercise
    demonstrate that bad tests can hide bad code

user errors
    exceptions

IsPrime
    1. identify the bad tests
    2. fix the tests
    3. identify the bad code
    4. fix the code
*/

// using return

int f (...) {
    ...
    if (<something wrong>)
        return -1;
    ...

int g (...) {
    ...
    int i = f(...);
    if (i == -1)
        <something wrong>
    ...

...
...g(...)...
...

// using global

int h = 0;

int f (...) {
    h = 0;
    ...
    if (<something wrong>) {
        h = -1;
        return ...}
    ...

int g (...) {
    ...
    int i = f(...);
    if (h == -1)
        <something wrong>
    ...

...
...g(...)...
...

// using parameter

int f (..., int& e2) {
    ...
    if (<something wrong>) {
        e2 = -1;
        return ...}
    ...

int g (...) {
    ...
    int e = 0;
    int i = f(..., e);
    if (e == -1)
        <something wrong>
    ...

...
...g(...)...
...

/*
three avenues of communication
    1. returns
    2. globals
    3. parameters

assertions bad
    because they'll halt the code

returns, globals, parameters bad
    because they can be ignored
*/

// using exception

int f (...) {
    ...
    if (<something wrong>)
        throw E(...);      // throw always copies
    ...}

int g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (E& e)          // always catch by refernce
        <something wrong>
    ...}

...
...g(...)...
...

/*
Java
    builtin      types are on the stack
    user-defined types are on the heap

C++
    either can be in either

1. no exception was thrown
2. exception was thrown and handled
3. exception was thrown and not handled

a throw in a catch clause always goes to the next higher try block

catch clauses of types in a class hierarchy must list children first
*/

/*
Questions
    What were the two bugs in IsPrime1?
    What was the inefficiency in IsPrime1?
    In using a parameter for error handling, why was the parameter passed by reference?
    Could it have been passed by value?
    Could it have been passed by address?
    Why does throw always copy?
    Why should you catch by reference?
*/
