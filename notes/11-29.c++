// -----------
// Wed, 29 Nov
// -----------

class  A : B {...} // implies private inheritance
struct A : B {...} // implies public  inheritance

struct A {
    void f (int) {...}}

struct B : A {}

int main () {
    B x;
    x.f(2);

    A* p = &x;}

// In Java
class stack extends vector {...}

// In C++
class stack : public vector {...} // same problem

class stack : private vector {...} // don't have that problem

vector<AS*> x(s, new Circle(...));         // crazy, only 1 Circle, lazy, too lazy

vector<Shape> y(s, Shape(new Circle(...))) // fine, s Circles, eager, maybe too eager

vector<Cell> z(s, Cell(new ConwayCell(...))

// copy on write (COW)

vector<Cell> z(s, Cell(new ConwayCell(...)) // build one ConwayCell

class Cell {
    private:
        struct RC {
            AbstractCell* _p;
            int _c;}

        RC* _q;

    public:
        Cell (const Cell& _rhs) :
            _q (rhs._q) {
            ++_q->_c;}

        ~Cell () {
            if (_q->_c == 1) {
                delete _q->_p;
                delete _q;}
            else
                --_q->_c;}

        Cell& operator = (const Cell& rhs) {
            Cell tmp(rhs);
            swap(_q, tmp._q);
            return *this;}
