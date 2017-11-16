// -----------
// Wed, 15 Nov
// -----------

A x(2, 3, 4);
A y(2, 3);
A z(2);
A t(); // a func decl
A t;

A* p = new A(2, 3, 4);
A* p = new A(2, 3);
A* p = new A(2);
A* p = new A();
A* p = new A;

/*
Conway cells

two states
    dead
    alive

define neighborhood
    north
    west
    east
    south
    all diagonals

if the cell is alive and has three live neighbors
    cell stays alive
else
    dies

if the cell is dead and two OR three neighbors are alive
    cell becomes alive
else
    stats dead
*/

/*
..*
...
...
*/

/*
Life
    left to right
    top to bottom
*/

/*
60 x 100 -> 6000 cells
35 live
remaining as dead

gen 0
    pop 35
gen 180
    pop 500
gen 220
    pop 200
never changes again
*/

/*
very, very complex behavior
from simple rules
simple initial conditions
*/

class AbstractCell {...};

class ConwayCell : public AbstractCell {...};

class FredkinCell : public AbstractCell {...};

template <typename T>
class Life {...};

int main () {
    Life<ConwayCell> x(...);
    // run simulation

    Life<FredkinCell> y(...);
    // run simulation

    vector<ConwayCell> x(s, v);

    vector<FredkinCell> y(s, w);

    vector<AbstractCell> z(s, v);

    ConwayCell v(...);
    vector<AbstractCell*> t(s, &v); // isn't right

    vector<AbstractCell*> a(s);
    fill(a, a + s, &v);         // still isn't right

{
    vector<AbstractCell*> b;
    for (int i = 0; i != s; ++i)
        b.push_back(new ConwayCell(...));
    b.push_back(new FredkinCell(...));
}
