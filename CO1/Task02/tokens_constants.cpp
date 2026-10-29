#include <iostream>
#include <string_view>

enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};

int main() {
    Zone zone = Zone::Outer;
    const bool peak = true;
    const long long base = BASE_PAISE[static_cast<int>(zone)];
    const long long fare = peak ? base + base * PEAK_SURCHARGE_PERCENT / 100 : base;
    std::cout << "Fare paise: " << fare << "\nMinimum balance paise: " << MIN_BALANCE_PAISE << '\n';
}
