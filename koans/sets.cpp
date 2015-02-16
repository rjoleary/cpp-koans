#include <set>
#include <string>

#include "koans_common.hpp"


// a simple class for demonstration
class Money {
    public:
        Money(int d, int c) {dollars = d; cents = c;}
        int GetDollars() const {return dollars;}
        int GetCents() const {return cents;}
    private:
        int dollars, cents;
};


int main() {
	// 0. INTRODUCTION
	// A set is a container of unique elements which is both associative and ordered.
	// It is associative because elements are accessed based on their value, not an index.
	// It is ordered because elements are always sorted from smallest to largest (or in another specified order).
	// A set cannot contain two of the same element; each element is unique.

	// Correct the code below by replacing only the occurances of `MISSING` with an expression.
	// Each `rule` must evaluate to true.


	// 1. CONSTRUCTION
	// Unless copied from another set, a set will start with 0 elements.
	// set of int starting with 0 elements
    std::set<int> a;

	// set of string starting with 0 elements
    std::set<string> b;


	// 2. INSERT ELEMENTS
	// Elements can be inserted into a set.
	// New elements are guaranteed to be placed in order.
	// If an element already exists in the set, it will not be inserted a second time.
	// The `size` member function returns the size of the set.
	// The `empty` member function returns true when the size is 0.
	rule(a.empty() == MISSING);
	rule(b.size() == MISSING);

	a.insert(0);
	a.insert(2);
	a.insert(4);
	a.insert(2);
	a.insert(-5);
	rule(a.size() == MISSING);
	a.insert(MISSING);
	rule(a.size() == 4);

	for (int n = 0; n < 10; n++) {
		b.insert(string(n, '*'));
		b.insert(string(n * 2, '*'));
	}
	rule(b.size() == MISSING);

	// 3. FIND ELEMENTS


	// 4. ITERATORS
	// Iterators act like a pointer to a specific element in a vector.
	// They can be dereferenced (`*` operator) to get the value of the pointed element.
	// `vector.begin()` is an iterator to the first element in the vector.
	// `vector.end()` is an iterator to one past the last element in the vector.
	// `vector.end()` cannot be dereferenced since it points outside the vector's range.
    std::vector<int> f(6);
	f[0] = 5; f[1] = 4; f[2] = 3; f[3] = 2; f[4] = 1; f[5] = 0;
	rule(*f.begin() == 5);

	// Iterators can be incremented to point to the next element,
	//  or they can be decremented to point to the previous element
	rule(*++f.begin() == 4); // note that `--` and `++` has higher precedence than `*`
	rule(*--f.end() == 0);
	rule(*++++f.begin() == 3);

	// A positive integer can be added to an iterator to move the pointer forward by that many elements.
	rule(*(f.begin() + 2) == 3);
	rule(*(f.begin() + 3) == 2);
	rule(*(f.end() - 2) == 1);
	rule(*(f.end() - 6) == 5);

	// Iterators tested for equality. If they point to the same element, the test returns true.
	rule(f.begin() == f.end() - 6);
	rule(f.begin() + 6 == f.end());

	// Iterators can be stored as a variable and manipulated.
	// This is useful for loops.
	// A variable of type `auto` will automatically determine the proper type.
	sum = 0;
	for (auto i = d.begin(); i != d.end(); ++i) {
		sum += i->GetDollars() * 100 + i->GetCents();
    }
	rule(sum == 8146);


	// 5. ERASE ELEMENTS
	// The `erase` member function can delete a single element via an iterator.
    std::vector<bool> g;
	for (int i = 0; i < 10; i++) {
		g.push_back(i % 2 == 0);
    }
	rule(g[0] == true);
	g.erase(g.begin());
	rule(g[1] == true);
	g.erase(g.begin() + 8);
	rule(g[7] == true);
	g.erase(g.end() - 1);
	rule(g.size() == 7);

	// `erase` can also delete a multiple elements between two iterators.
	// The elements deleted are on the interval [b,e).
	g.erase(g.begin() + 1, g.end() - 2);
	rule(g.size() == 3);
	rule(*(g.end()-1) == false);
	g.erase(g.begin(), g.end());
	rule(g.size() == 0);


	// 7. DELETE


	// 8. RELATIONAL OPERATORS


	// 10. THE OTHERS
	// Predict and write down what they do.
	// clear
	// lower_bound
	// upper_bound

	// 11. MULTISET
	// count
	// lower_bound
	// upper_bound


	// 11. MORE PROBLEMS

}
