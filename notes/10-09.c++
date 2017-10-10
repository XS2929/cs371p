// -----------
// Mon,  9 Oct
// -----------

/*
Range
*/

/*
Test #1
Canvas:     multiple-choice questions
HackerRank: code-writing    questions
*/

/*
iterator categories
*/

/*
input iterator
    * (read only), ++, ==, !=
    as an example
        equal can use this
        copy  can use this
*/

/*
output iterator
    * (write only), ++
    as an example
        fill can't use this
        copy can   use this
/*

/*
forward iterator
    * (read/write), ++, ==, !=
    as an example
        fill    can   use this
        reverse can't use this
*/

/*
bidirectional iterator
    * (read/write), ++, --, ==, !=
    as an example
        reverse can   use this
        sort    can't use this
*/

/*
random access iterator
    * (read/write), ++, --, ==, !=, [], +/- with int, -, <, >, <=, >=
    as an example
        sort can use this
*/

/*
in Java
    two kinds of inner classes
        non-static
        static

    two nice examples are in LinkedList
        Iter is a non-static inner class
        Node is a static     inner class
*/

class A {
    int i;

    public class B { // non-static inner class
        int j;

        public void f () {
            ++j;
            ++this.j;
            ++A.this.i;


    public static class C {...}}

class T {
    public void static main (...) {
        x = new A();  // no B object

        y = new A.B(); // not ok
        z = new A.C();

        y = x.new B();

/*
in C++
    only one kind of inner class
        static
*/

class A {
    class B {}}; // it's like a Java STATIC inner class

int main () {
    A x;
    A.B y;
