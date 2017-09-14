// -----------
// Wed, 13 Sep
// -----------

/*
exercise
    demonstrate that bad tests can hide bad code

user errors
    exceptions

exceptions
type
l-values / r-values

in C
    strings are really char*, c strings

in C++
    some strings are char*,       C   strings
    some strings are std::string, C++ strings

domain_error::what() -> char*

two possibilities for
    std::string == char*

1. operator == (std::string, char*)

2. std::string implicitly converts to a char*

3. char* implicitly converts to a std::string; this is what wins
*/

class string {
    public:
        explicit string (char* a) { // constructor, implicit type converter from char* to string
            ...}};

void f (string t) {
    ...}

int main () {
    string s("abc");
    f(s);
    f(string("def"));
    f("ghi");         // fails with explicit

struct A {
    void g () {}};

struct B : A {}
    void g () {}};

void f (A x) {
    x.g();}    // always A::g()

int main () {
    B y;
    f(y);

/*
Questions:
    How do you compare the identity of two C   strings?
    How do you compare the value    of two C   strings?
    How do you compare the identity of two C++ strings?
    How do you compare the value    of two C++ strings?
    Besides being a constructor, what does a one-arg constructor define?
    How do you turn that off?
*/
