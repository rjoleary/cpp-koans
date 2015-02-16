#include <stdexcept>
#include <vector>

#include "koans_common.hpp"


// A simple class for demonstration
class Money {
    public:
        Money(int d, int c) {dollars = d; cents = c;}
        int getDollars() const {return dollars;}
        int getCents() const {return cents;}
    private:
        int dollars, cents;
};


int main() {
    // 0. INTRODUCTION
    // A vector is similar to an array, except it can be resized and contains many helpful member functions.
    // Correct the code below by only replacing the occurances of `MISSING` with an expression.
    // Each `rule` must evaluate to true.


    // 1. CONSTRUCTION
    // vector of int starting with 0 elements
    std::vector<int> a;

    // vector of int starting with 10 elements initialized to the default value 0
    std::vector<int> b(10);

    // vector of bool starting with 2 elements initialized to false
    std::vector<bool> c(2, false);

    // vector of Money starting with 4 elements initialized to Money(19, 99)
    std::vector<Money> d(4, Money(19, 99));


    // 2. SIZE
    // Vectors remember their size, the number of elements they contain.
    rule(a.size() == 0);
    rule(c.size() == 2);
    rule(d.size() == MISSING);
    std::vector<char> e(MISSING);
    rule(e.size() == 40);

    // The `empty` member function returns true when the size is 0.
    rule(a.empty() == MISSING);
    rule(b.empty() == MISSING);


    // 3. Indexing
    // An element's value can be accessed using the `at` function with a 0-based index.
    // Elements can be read or written to.
    // This operation is fast (constant time).
    b.at(0) = 6;
    b.at(4) = 5;
    rule(b.at(0) == MISSING);
    rule(b.at(MISSING) == 1 + b.at(MISSING));
    rule(b.at(MISSING) == 0);

    c.at(0) = true;
    rule(c.at(0) != c.at(MISSING));
    rule(d.at(1).getDollars() * 100 + d.at(2).getCents() == MISSING);

    int sum = 0;
    for (int n = 0; n < (int)d.size(); n++) {
        sum += d.at(n).getDollars() * 100 + d.at(n).getCents();
    }
    rule(sum == MISSING);

    // Accessing an invalid index will throw an `out_of_range` exception.
    try {
        c.at(MISSING) = 7;
        rule(false); // We do not want to run this line.
    } catch (const std::out_of_range &x) {
    }


    // 4. INSERT ELEMENT AT END
    // `push_back` will insert an element at the end of the vector.
    // The function is useful when reading an array from a file of unknown length.
    // This operation is fast (constant amortized time).
    a.push_back(6);
    a.push_back(7);
    rule(a.size() == MISSING);
    rule(a.at(0) == MISSING);
    rule(a.at(MISSING) == 7);
    d.push_back(Money(1, 50));
    rule(d.at(MISSING).getCents() == 50);


    // 5. ITERATORS
    // Iterators act like a pointer to a specific element in a vector.
    // They can be dereferenced (`*` operator) to get the value of the pointed element.
    // `vector.begin()` is an iterator to the first element in the vector.
    // `vector.end()` is an iterator to one past the last element in the vector.
    // `vector.end()` cannot be dereferenced since it points outside the vector's range.
    std::vector<int> f(6);
    f.at(0) = 5; f.at(1) = 4; f.at(2) = 3; f.at(3) = 2; f.at(4) = 1; f.at(5) = 0;
    rule(*f.begin() == MISSING);

    // Iterators can be incremented to point to the next element,
    //  or they can be decremented to point to the previous element
    rule(*++f.begin() == 4); // note that `--` and `++` has higher precedence than `*`
    rule(*--f.end() == MISSING);
    rule(*++++f.begin() == MISSING);

    // A positive integer can be added to an iterator to move the pointer forward by that many elements.
    rule(*(f.begin() + 2) == 3);
    rule(*(f.begin() + 3) == MISSING);
    rule(*(f.end() - 2) == MISSING);
    rule(*(f.end() - MISSING) == 5);

    // Iterators tested for equality. If they point to the same element, the test returns true.
    rule(f.begin() == f.end() - MISSING);
    rule(f.begin() + MISSING == f.end());

    // Iterators can be stored as a variable and manipulated.
    // This is useful for loops.
    // A variable of type `auto` will automatically determine the proper type.
    sum = 0;
    for (auto i = d.begin(); i != d.end(); ++i)
        sum += i->getDollars() * 100 + i->getCents();
    rule(sum == MISSING);


    // 6. DELETE ELEMENTS
    // The `erase` member function can delete a single element via an iterator.
    // This operation is slow (linear time).
    std::vector<bool> g;
    for (int i = 0; i < 10; i++)
        g.push_back(i % 2 == 0);
    rule(g.at(0) == MISSING);
    g.erase(g.begin());
    rule(g.at(1) == MISSING);
    g.erase(g.begin() + MISSING);
    rule(g.at(7) == true);
    g.erase(g.end() - 1);
    rule(g.size() == MISSING);

    // `erase` can also delete a multiple elements between two iterators.
    // The elements deleted are on the interval [b,e).
    g.erase(g.begin() + 1, g.end() - 2);
    rule(g.size() == MISSING);
    rule(*(g.end()-1) == MISSING);
    g.erase(g.begin(), g.end());
    rule(g.size() == MISSING);


    // 7. INSERT ELEMENTS
    // Multiple elements can be inserted into a vector from an array or another vector.
    // The `insert` functions takes an iterator of where to insert the values and two iterators from another vector.
    // This operation is slow (linear time).
    std::vector<double> h;
    double k[4] = {3.0, 5.6, 7.8, 10.4};
    h.insert(h.begin(), k, k + 4);
    rule(h.size() == MISSING);
    h.insert(h.end() - MISSING, h.begin(), h.begin() + MISSING);
    rule(h.size() == 7);
    rule(h.at(6) == 10.4);
    rule(h.at(3) == 3.0);

    // `insert` can also be used to insert single elements.
    h.insert(h.begin() + 1, 40.2);
    rule(h.at(1) == MISSING);
    rule(h.at(2) == MISSING);
    rule(h.size() == MISSING);


    // 8. RELATIONAL OPERATORS
    // TODO


    // 9. Resize
    // Remember that inserting elements, deleting elements or resizing a vector will invalidate its iterators.
    // TODO


    // 10. THE OTHERS
    // Predict and write down what they do.
    // front
    // back
    // clear
    // pop_back
    // TODO


    // 11. MORE PROBLEMS
    // Do the following problems using vectors. Only `resize` or `push_back` when needed.
    //  CCC 2013 Senior Problem 2 : http://cemc.uwaterloo.ca/contests/computing/2013/stage1/seniorEn.pdf
    //  CCC 2003 State 2 Day 1 Problem 1: http://cemc.uwaterloo.ca/contests/computing/2003/stage2/bf/1_bf.pdf
    //  ECOO 2006 Board Problem 1: http://ecoocs.org/contests/ecoo_2006.pdf
    //  Project Euler Problem 13: http://projecteuler.net/problem=13
}
