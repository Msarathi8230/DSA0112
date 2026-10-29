#include <iomanip>
#include <iostream>
#include <limits>
int main() {
    int hour{};
    std::cout << "Enter hour (0-23): ";
    while (!(std::cin >> hour) || hour < 0 || hour > 23) {
        if (std::cin.eof()) return 1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid hour. Enter 0-23: ";
    }
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    const int farePaise = peak ? 1200 : 1000;
    std::cout << "Period: " << (peak ? "Peak" : "Off-peak") << "\nFare: Rs "
              << farePaise / 100 << '.' << std::setw(2) << std::setfill('0') << farePaise % 100 << '\n';
}
