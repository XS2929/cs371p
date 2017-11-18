// -----------
// Fri, 17 Nov
// -----------

vector<T> x(s, v);

Cell x = new ConwayCell(...);
Cell y = new FredkinCell(...);

AbstractCell* p = new ConwayCell(...);
Cell x = p;
Cell y = p; // don't do this

class Shape {...};

class Circle : public Shape {...};

class Triangle : public Shape {
    public Triangle (...) {...}};

int main () {
    Shape* p = new Triangle(...);
    cout << p->area();            // 0
    delete p;

// In Java

abstract class A {
    public abstract void f (int i);};

class B extends A {
    void f (int i) {...}}

/*
what are the consequences of a an abstract method
    1. the class must be abstract
    2. the children must define the method or be declared abstract
    3. prohibits the definition of f in A
*/

// In C++

class A {
    public virtual void f (int i) = 0;}

void A::f (int i) {...} // optional

class B : public A {
    void f (int i) {...}}

/*
what are the consequences of a an pure virtual method
    1. the class must be abstract
    2. the children must define the method or become abstract
    3. optional definition of f in A
*/

int main () {
    A  x;           // not ok
    A* p = new A;   // not ok
    A* q = nullptr;

class A {
    public virtual ~A () = 0;}

A::~A () {} // required

class B : public A {
    void f (int i) {...}}
/*
what are the consequences of a an pure virtual destructor
    1. the class must be abstract
    2.
    3.
*/

// In Java

abstract class A {
    public          void f (long) {...}   // runtime logic error
    public final    void g (long) {...}
    public abstract void h (long) {...}}

class B extends A {
    void f (int) {...}
    void h (int) {...}}; // not ok

class T {
    public static void main (...) {
        A x = new B();
        x.f(2);                     // A.f

// in C++

class A {
    public:
                void f (long)       {...} // runtime logic error
        virtual void g (long) final {...}
        virtual void h (long) = 0;};

class B : public A {
    public:
        void f (int) {...}
        void h (int) {...}}; // not ok

int main () {
    A* p = new B;
    p->(2);      // A::f
    return 0;}
