// -----------
// Fri, 15 Sep
// -----------

/*
exceptions

types

C++'s vector is like Java's ArrayList
vector and ArrayList have FRONT loaded arrays
costs
    insertion at the back:   O(1), amortized
    insertion anywhere else: O(n)
    indexing:                O(1)

C++'s list is like Java's LinkedList
list and LinkedList are doubly-linked lists
costs
    insertion anywhere: O(1)
    indexing:           O(n), not available in C++

C++'s deque is like Java's ArrayDeque
deque and ArrayDeque have MIDDLE loaded arrays
deque has an array of arrays
deque has a more expensive O(1) indexing, because of the additional divide, mod, and add
a lot cheaper to grow deque vs vector
*/

vector<int> x(10, 2);
int* p = &x[5];

cout << *p; // 2

x.push_back(3); // O(n)

cout << *p; // undefined

/*
stack can be backed by vector, deque, and list
queue can be backed by deque and list

priority_queue with a non-sorted vector
    O(1) to push
    O(n) to pop
priority_queue with a sorted vector
    O(n) to push
    O(1) to pop
priority_queue with a binary heap
    O(log n) to push and pop
priority_queue can be backed by vector and deque
*/

/*
Questions
    Why is deque middle loaded?
    Why is deque an array of arrays?
    The default backing of stack          is deque,  not vector. Why?
    The default backing of queue          is deque,  not vector. Why?
    The default backing of priority_queue is vector, not deque.  Why?
*/
