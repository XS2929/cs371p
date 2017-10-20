// -----------
// Fri, 20 Oct
// -----------

int i; // declaration
i = 2; // assignment

vs.

int i = 2; // initialization

Mammal x;
Tiger  y;

Mammal* p = &x;
p = &y;         // ok

Tiger* q = &y;
q = &x;        // not ok

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;

    public:
        vector () {
            _s = 0;
            _a = nullptr;}

        int size () const {
            return _s;}
