// -----------
// Mon, 23 Oct
// -----------

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;

    public:
        vector () {
            _s = 0;
            _a = nullptr;}

        vector (int size) {
            _s = size;
            _a = new T[_s];
            fill(_a, _a + _s, T());}

        vector (int size, const T& v) {
            _s = size;
            _a = new T[_s];
            fill(_a, _a + _s, v);}

        vector (initializer_list<T> il) {
            _s = il.size();
            _a = new T[_s];
            copy(il.begin(), il.end(), _a);}

        T* begin () {
            return _a;}

        const T* begin () const {
            return _a;}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return _a + _s;}

        int size () const {
            return _s;}

        T& operator [] (int i) {
            return _a[i];}

        const T& operator [] (int i) const {
            return _a[i];}};
