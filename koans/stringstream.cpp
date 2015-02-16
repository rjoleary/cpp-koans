#include <complex>
#include <locale>
#include <sstream>
#include <string>

#include "koans_common.hpp"


// A simple class for demonstration
class Money {
public:
	Money(int d, int c) {dollars = d; cents = c;}
	int GetDollars() const {return dollars;}
	int GetCents() const {return cents;}
private:
	int dollars, cents;
};


int main()
{
	// 0. INTRODUCTION
	// A set is a container of unique elements which is both associative and ordered.
	// It is associative because elements are accessed based on their value, not an index.
	// It is ordered because elements are always sorted from smallest to largest (or in another specified order).
	// A set cannot contain two of the same element; each element is unique.

	// Correct the code below by replacing only the occurances of `MISSING` with an expression.
	// Each `rule` must evaluate to true.


	// 1. CONSTRUCTION
	// An `ostringstream` behaves similarily to an ostream, ofstream or cout.
    std::ostringstream oss;

	// An `istringstream` behaves similarily to an istream, ifstream or cin.
    std::istringstream iss;

	// A `stringstream` acts both like a `ostringstream` and an `istringstream`.
    std::stringstream ss;


	// 2. STREAM INSERTION
	// The stream insertion operator can only be used on `ostringstream` and `istringstream`.
	oss << "Hello, " << "the product of ";
	oss << "45 and 71 is " << 45 * 71;
	// The content of a string stream can be read back with the `str` member function.
	rule(oss.str() == "MISSING");
	// The stream insertion operator has many overloads for built-in types and standard classes.
	ss << std::complex<double>(4, 3) * std::complex<double>(MISSING, MISSING);
	rule(ss.str() == "(-3,4)");

	// The `str` member function can also be used to set contents of a string stream.
	// This works for all types of string streams.
	iss.str("I am a string inside an istringstream.");
	rule(MISSING == "I am a string inside an istringstream.");
	// The function is also useful for clearing the contents of a string stream.
	oss.str("");
	iss.str("");
	ss.str("MISSING");
	rule(ss.str().empty());


	// X. LOCALE
	// Each region has a different way of writing numbers, dates and times.
	// For example, here are some differences between English and French:
	//  English: 12,345.67
	//  French:  12 345,67

	// The locale of the current computer can be selected with an empty string argument.
    std::stringstream currentLocale;
	currentLocale.imbue(locale(""));
	currentLocale << 1000;
	rule(currentLocale.str() == "MISSING");
	currentLocale.str("2,999.99");
	double n;
	currentLocale >> n;
	rule(int(n) == MISSING);

	// The locale can be set to a specific language.
    std::stringstream frenchLocale;
	frenchLocale.imbue(locale("french"));
	frenchLocale << 1e9 + 0.25;
	// Note that the thousands' digit seperator is a non-breaking space '\xAO'.
	rule(frenchLocale.str() == "MISSING");

	// X. MORE PROBLEMS

}
