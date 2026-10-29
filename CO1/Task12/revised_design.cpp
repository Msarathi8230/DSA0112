#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
enum class Zone { Inner=0, Middle=1, Outer=2, Airport=3 };
constexpr std::array<long long,4> BASE_PAISE{1000,2000,3000,6000};
constexpr long long MIN_BALANCE_PAISE=5000;
constexpr int PEAK_PERCENT=20, WEEKEND_DISCOUNT_PERCENT=10;
struct FareRequest { Zone zone; int hour; bool weekend; };
std::optional<long long> calculateFare(const FareRequest& r) {
    if (r.hour<0 || r.hour>23) return std::nullopt;
    long long base=BASE_PAISE.at(static_cast<std::size_t>(r.zone));
    const bool peak=(r.hour>=8 && r.hour<10)||(r.hour>=17 && r.hour<20);
    // Stated rule: weekend discount does not combine with peak surcharge.
    if (r.weekend) return base - base*WEEKEND_DISCOUNT_PERCENT/100;
    if (peak) return base + base*PEAK_PERCENT/100;
    return base;
}
class MonthlyPass {
    std::array<bool,4> zones_{};
public:
    MonthlyPass(Zone a, Zone b) { zones_.at(static_cast<std::size_t>(a))=true; zones_.at(static_cast<std::size_t>(b))=true; }
    bool covers(Zone z) const { return zones_.at(static_cast<std::size_t>(z)); }
};
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long b):balance_(b>=0?b:0){}
    bool canTravel(long long f) const { return f>=0 && balance_>=f && balance_-f>=MIN_BALANCE_PAISE; }
    bool deduct(long long f) { if(!canTravel(f)) return false; balance_-=f; return true; }
    long long balance() const{return balance_;}
};
int main(){
    auto airportPeak=calculateFare({Zone::Airport,18,false});
    auto airportWeekend=calculateFare({Zone::Airport,18,true});
    std::cout<<"Airport peak fare paise="<<*airportPeak<<" (Rs 72.00)\n";
    std::cout<<"Airport weekend fare paise="<<*airportWeekend<<" (Rs 54.00)\n";
    MonthlyPass pass(Zone::Inner,Zone::Airport);
    std::cout<<"Pass covers Inner="<<pass.covers(Zone::Inner)<<", Outer="<<pass.covers(Zone::Outer)<<"\n";
    SmartCard card(10000); std::cout<<"Rs100 card can pay Rs72 and retain Rs50? "<<card.canTravel(*airportPeak)<<"\n";
}
