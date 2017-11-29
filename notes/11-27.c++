// -----------
// Mon, 27 Nov
// -----------

/*
Java, dynamic binding turned off

1. private methods
2. final methods
3. final class
4. static methods
*/

class A {
    public static void f (...) {...}}

/*
C++
*/

struct A {
    A () {f();}
    virtual ~A () {f();}
    virtual void f (int) {...}};

struct B : A {
    void f (int) {...}};

int main () {
    A* p = new B; // A::f, statically bound and can be inlined
    p->f(2);      // B::f

    B x;
    x.f(2); // statically bound and can be inlined

    p->A::f(2); // statically bound and can be inlined

    delete p; // A::f, statically bound and can be inlined

Shape2 x = new Circle(...);
Shape2 y = new Triangle(...);
Shape2 z = x;
z = y;

cout << x.area(); // if x where Shape1

cout << (*x).area();          // if x is Shape2
cout << x.operator*().area();
x.operator*().move();

cout << x->area();            // if x were a real pointer
cout << x.operator->()->area();

const Shape2 t = new Circle(...);
t.operator*().move();


class Shape2 {
    private:
        AS* _p;

    public:
        AS& operator * () {
            return *_p;}

        const AS& operator * () const {
            return *_p;}

        AS* operator -> () {
            return _p;}

        const AS* operator -> () const {
            return _p;}
