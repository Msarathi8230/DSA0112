#include <iostream>
constexpr long long MIN_BALANCE = 5000;
bool canTravel(long long balance, long long fare) { return fare >= 0 && balance - fare >= MIN_BALANCE; }
bool deduct(long long& balance, long long fare) { if (!canTravel(balance, fare)) return false; balance -= fare; return true; }
int main() { long long balance = 10000; long long f = 3000; std::cout << (deduct(balance, f) ? "Accepted" : "Denied") << ", balance paise=" << balance << '\n'; }
