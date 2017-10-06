// -----------
// Fri,  6 Oct
// -----------

/*
RangeIterator
classes
friends
*/

/*
in Java
*/

class A {
    public    void f () {...} // everybody
    private   void g () {...} // only A
    protected void h () {...} // A, its descendents, same package
              void m () {...} // same pacakge

/*
in C++
*/

class A {
    friend class B
    friend C::foo;
    friend int bar (int, int);

    void m () {...} // with class, private; with struct, public

    public:
        void f () {...} // everybody

    private:
        void g () {...} // only A, friends

    protected:
        void h () {...} // A, its descendents, friends

/*
struct or class can be used
with class  by default everything is private
with struct by default everything is public
there's a convention, that if everything is public, use struct
otherwise use class
*/

/*
friend in C++

who can make the declaration?
    only classes
who can the declaration be about?
    another class, a method of another class, a function
what does a friend have access?
    everything
friendship is not transitive
friendship is not symmetric
*/

/*
Questions
    What do the access directives mean in Java?
    What do the access directives mean in C++?
    Does C++ have namespace access, like Java has package access?
    Does Java have friends?
    How does class differ from struct in C++?
*/
