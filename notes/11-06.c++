// -----------
// Mon,  6 Nov
// -----------

template <typename T>
struct A {
    int        iv;
    static int cv; // in Java, only 1

/*
5 A<int>
5 A<double>
5 A<elephant>

how many iv? 15
how many cv?  3
*/

// inside of non-const non-static method
T* const this;

// inside of const non-static method
const T* const this;

/* local variable
how many are there: one per call, coexistence with recursion
when is it allocated: on function entry
when is it initialized: one per call, at the line
what is it's lifetime: lifetime of the function
what is it's scope: the function, after the line
*/

void f () {
    ...
    int i = g(...);
    ...

/* static local variable
how many are there: one
when is it allocated: on program entry
when is it initialized: firt call, at the line
what is it's lifetime: lifetime of the program
what is it's scope: the function, after the line
*/

void f () {
    ...
    static int i = g(...);
    ...

/* global variable
how many are there: one
when is it allocated: on program entry
when is it initialized: before main()
what is it's lifetime: lifetime of the program
what is it's scope: the program
*/

// foo.c++
int i = g(...); // not ok in C, has no meaning in Java, ok in C++
int j = i;
int k;

void f () {
    ...
    ++i;

// bar.c++

extern int k;

void h () {
    ...
    ++i;}

/* static global variable
how many are there: one
when is it allocated: on program entry
when is it initialized: before main()
what is it's lifetime: lifetime of the program
what is it's scope: the file
*/

// i.h
static int i;


// foo.c++
#include "i.h"

void f () {
    ...
    ++i;

// bar.c++

#include "i.h"

void h () {
    ...
    ++i;}
