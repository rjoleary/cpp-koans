#ifndef KOANS_COMMON_HPP__INCLUDED
#define KOANS_COMMON_HPP__INCLUDED

#include <iostream>
#include <cstdlib>

#define rule(expr) while (!(expr)) {std::cerr << __FILE__ ": Broken rule on line " << __LINE__ << "\n"; std::exit(0);}
#define MISSING (std::cerr << __FILE__ ": Fill in MISSING on line " << __LINE__ << "\n", 0)

#endif // KOANS_COMMON_HPP__INCLUDED
