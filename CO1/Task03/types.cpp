#include <climits>
#include <iostream>
#include <limits>
int main() {
    std::cout << "sizeof(bool)=" << sizeof(bool) << "\n";
    std::cout << "sizeof(char)=" << sizeof(char) << "\n";
    std::cout << "sizeof(int)=" << sizeof(int) << "\n";
    std::cout << "sizeof(unsigned)=" << sizeof(unsigned) << "\n";
    std::cout << "sizeof(long long)=" << sizeof(long long) << "\n";
    std::cout << "sizeof(float)=" << sizeof(float) << "\n";
    std::cout << "sizeof(double)=" << sizeof(double) << "\n";
    std::cout << "INT_MAX=" << INT_MAX << " LLONG_MAX=" << LLONG_MAX << "\n";
    const long long journeys = 3000000;
    const long long maxFarePaise = 3600;
    std::cout << "3M journeys at Rs36 max: Rs " << journeys * maxFarePaise / 100 << "\n";
    double sum = 0.0; for (int i=0;i<1000000;++i) sum += 0.1;
    std::cout.precision(17); std::cout << "1M x 0.1 double = " << sum << "\n";
    std::cout << "1M x 10 paise integer = " << 1000000LL * 10 << " paise\n";
}
