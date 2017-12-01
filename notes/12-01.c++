// -----------
// Fri,  1 Dec
// -----------

Shape x = new Circle(...);
Shape x(new Circle(...));

template <typename T>
class unique_ptr {
    private:
        T* _p;

    public:
        explicit unique_ptr (T* p) {
            _p = p;}

        ~unique_ptr () {
            delete _p;}

        // unique_ptr (const unique_ptr&) = delete;
        // unique_ptr& operator = (const unique_ptr&) = delete;

        unique_ptr (unique_ptr&& rhs) {
            _p = rhs._p;
            rhs._p = nullptr;}

        unique_ptr& operator = (unique_ptr&& rhs) {
            delete _p;
            _p = rhs._p;
            rhs._p = nullptr;
            return *this;}
