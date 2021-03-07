#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

string truncateAsString(double n, int precision) {
    stringstream ss;
    double remainder = static_cast<double>((int)floor((n - floor(n)) * precision) % precision);
    ss << setprecision(numeric_limits<double> ::max_digits10 + __builtin_ctz(precision))<< floor(n);
    if (remainder)
        ss << "." << remainder;
    cout << ss.str() << "%" << endl;
    return ss.str();
}

int main(void) {
    double a =  0.02785;
    int precision = 100; // as many digits as you add zeroes. 3 zeroes means precision of 3.
    string s = truncateAsString(a*100 + 0.5 / 100, precision);
    return 0;
}