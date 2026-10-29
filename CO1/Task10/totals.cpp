#include <iomanip>
#include <iostream>
#include <limits>
int main() {
    const long long n[] = {20000, 500000, 3000000};
    const long long farePaise = 1200;
    for (long long count : n) {
        long long exact = count * farePaise;
        double rupees = static_cast<double>(count) * 12.0;
        std::cout << count << " journeys: integer paise=" << exact << ", rupees=" << std::fixed << std::setprecision(2) << rupees << '\n';
    }
    const long long networkAtRs36 = 3000000LL * 3600;
    std::cout << "3M x Rs36 in paise=" << networkAtRs36 << " (int max=" << std::numeric_limits<int>::max() << ")\n";
    double sum = 0.0; for (int i=0;i<3000000;++i) sum += 0.1;
    std::cout << std::setprecision(17) << "3M x Rs0.10 accumulated double=" << sum << '\n';
}
