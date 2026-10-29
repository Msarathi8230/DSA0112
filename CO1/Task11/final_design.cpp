#include <array>
#include <iostream>
#include <optional>
enum class Zone { Inner, Middle, Outer };
constexpr std::array<long long,3> FARES{1000,2000,3000};
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;
std::optional<long long> calculateFare(Zone zone, int hour) {
    if (hour < 0 || hour > 23) return std::nullopt;
    auto base = FARES.at(static_cast<std::size_t>(zone));
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base + base * PEAK_PERCENT / 100 : base;
}
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long paise) : balance_(paise >= 0 ? paise : 0) {}
    bool pay(long long fare) { if (fare < 0 || balance_ - fare < MIN_BALANCE_PAISE) return false; balance_ -= fare; return true; }
    long long balance() const { return balance_; }
};
int main() {
    SmartCard card(10000);
    auto f = calculateFare(Zone::Outer, 18);
    if (f && card.pay(*f)) std::cout << "Accepted fare=" << *f << " paise, balance=" << card.balance() << " paise\n";
    else std::cout << "Denied, balance=" << card.balance() << " paise\n";
}
