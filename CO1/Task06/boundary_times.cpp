#include <iostream>
bool isPeak(int hour) { return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20); }
int main() {
    for (int hour : {8, 10, 17, 20})
        std::cout << hour << ":00 is " << (isPeak(hour) ? "peak" : "off-peak") << '\n';
}
