#include <iostream>
class SmartCard {
    long long balance_;
    static constexpr long long MIN_BALANCE = 5000;
public:
    explicit SmartCard(long long initial) : balance_(initial >= 0 ? initial : 0) {}
    bool canTravel(long long fare) const { return fare >= 0 && balance_ >= fare && balance_ - fare >= MIN_BALANCE; }
    bool deduct(long long fare) { if (!canTravel(fare)) return false; balance_ -= fare; return true; }
    long long balance() const { return balance_; }
};
int main() { SmartCard card(10000); const bool ok = card.deduct(3000); std::cout << (ok ? "Accepted" : "Denied") << ", balance paise=" << card.balance() << '\n'; }
