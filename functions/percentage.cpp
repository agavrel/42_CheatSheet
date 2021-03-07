#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;
using boost::multiprecision::cpp_dec_float_50;

cpp_dec_float_50 truncate(cpp_dec_float_50 n, int precision) {
    cpp_dec_float_50 remainder = static_cast<cpp_dec_float_50>((int)floor((n - floor(n)) * precision) % precision) / static_cast<cpp_dec_float_50>(precision);
    return floor(n) + remainder;
}

int main(void) {
    int precision = 100; // as many digits as you add zeroes. 5 zeroes means precision of 5.
    cpp_dec_float_50 n =  0.02785 * 100;
    n = truncate(n + 0.5/precision, precision); // first part is remainder, floor(n) is int value truncated.
    cout << setprecision(numeric_limits<cpp_dec_float_50> ::max_digits10 + __builtin_ctz(precision)) << n << "%" << endl; // __builtin_ctz(precision) will equal the number of trailing 0, exactly the precision we need!
    return 0;
}