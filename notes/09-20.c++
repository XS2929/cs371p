// -----------
// Wed, 20 Sep
// -----------

/*
types

set
    no duplicates
    a red black binary search tree
    Java: TreeSet
    O(log n)

unordered
    no duplicates
    a hash table
    Java: HashSet
    O(1)

map
    no duplicate keys
    a red black binary search tree
    Java: TreeMap
    O(log n)

unordered
    no duplicate keys
    a hash table
    Java: HashMap
    O(1)

requirements T, where T is the type of element

any C++ container
    default constructible
    copy constructible
    copy assignable
    destructible

additional constraints for elements of sets or keys of maps
    <

additional constraints for elements an unordered set or keys of maps
    hashable
*/

int i = 2;
int j = 3;
int k = (i + j);
k = (2 + 3);
(i + j);         // not ok, + results in an expression, not a statement
(i + j) = k;     // not ok, + results in an r-value

/*
l-value is something that can be on the lhs of an assignment (e.g. i, j, k, NOT 2, 3)

r-value is something that can NOT be on the lhs of an assignment (e.g. 2, 3)

+ takes two r-values
+ results in an expression
+ results in an r-value
*/

i += j;
i += 3;
2 += 3;       // not ok, += takes an l-value on the left
k = (i += j); // not ok in Python; ok in C, Java, C++
(i += j) = k; // not ok in Python, C, Java; ok in C++

/*
+= takes an l-value and an r-value
+= results in a statement or an expression
+= results in an l-value
*/

i = 2;
k = ++i;   // does not make a copy
cout << i; // 3
cout << k; // 3

i = 2;
k = i++;   // makes a copy
cout << i; // 3
cout << k; // 2

i++ = k; // not ok, post increment results in an r-value
i++++;   // not ok

/*
post increment takes an l-value producing an r-value
*/

++i = k; // not ok in Python, C, Java; ok in C++
++++i;

for (int i = 0; i != s; i++)
    ...

{
int i = 0;
while (i != s) {
    ...
    i++;}        // compiler will rewrite to ++i
}

/*
If i is an instance of user-defined type, the compiler is not allowed to rewrite it.
Always use pre increment, when standalone.
*/

/*
Questions
    In terms of l-values and r-values, describe the arguments and returns of the following operators:
        +
        +=
        <<  (on int)
        <<  (on ostream)
        <<= (on int)
        >>  (on int)
        >>  (on istream)
        >>= (on int)
        ++  (pre  increment)
        ++  (post increment)
*/
