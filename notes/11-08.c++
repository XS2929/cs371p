// -----------
// Wed,  8 Nov
// -----------

struct A {
    int i;};

int main () {
    A x;
    x.i = 2;

    cout << x.i; // 2

    A* p = &x;
    cout << p.i;    // not ok
    cout << *p.i;   // not ok
    cout << (*p).i;
    cout << p->i;

/*
containment
    implementation

inheritance
    interfact
    implementation
*/

struct A {};

/*
A(A)
A()
=(A)
~A()
*/

class shape {
    private:
        int _x;
        int _y;

    public:
        Shape () = default;

        Shape (int x, int y) :
            _x (x),
            _y (y)
            {}

        Shape& operator = (const Shape&) = default;

        void move (int x, int y) {
            _x = x;
            _y = y;}

        double area () {
            return 0;}

class circle : public shape {
    private:
        int r;

    public:
        Circle (int x, int y, int r) :
            Shape(x, y),               // can't initialize _x or _y
            _r (r)
            {}

        double area () {
            return 3.14 * r * r;}

        int radius () {
            return r;}};

Shape* a = new Circle[5];
...
delete [] a; // only ~Shape() runs, not ~Circle(), which should also run
