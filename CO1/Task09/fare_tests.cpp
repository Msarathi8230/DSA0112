#include <iostream>
#include <limits>
#include <string>

enum class Zone : int { Inner=0, Middle=1, Outer=2 };
constexpr long long MIN_BALANCE_PAISE = 5000;
long long fare(int zone, int hour) {
    if (zone < 0 || zone > 2 || hour < 0 || hour > 23) return -1;
    const long long base[] = {1000, 2000, 3000};
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base[zone] + base[zone] * 20 / 100 : base[zone];
}
bool canTravel(long long balance, long long f) {
    return f >= 0 && balance >= f && balance - f >= MIN_BALANCE_PAISE;
}
bool recharge(long long& balance, long long amount) {
    if (amount < 0) return false;
    balance += amount;
    return true;
}
int main() {
    struct Test { const char* name; int zone; int hour; long long expected; };
    const Test tests[] = {
        {"Inner off-peak",0,7,1000}, {"Inner peak",0,8,1200},
        {"Middle off-peak",1,12,2000}, {"Middle peak",1,9,2400},
        {"Outer off-peak",2,12,3000}, {"Outer peak",2,18,3600},
        {"exact 08:00 peak",0,8,1200}, {"exact 10:00 off-peak",0,10,1000},
        {"exact 17:00 peak",0,17,1200}, {"exact 20:00 off-peak",0,20,1000},
        {"unknown zone",9,12,-1}, {"invalid hour",2,24,-1}
    };
    int failed=0;
    for (const auto& t: tests) {
        const long long actual=fare(t.zone,t.hour); const bool ok=actual==t.expected; if(!ok) ++failed;
        std::cout<<t.name<<": expected="<<t.expected<<" actual="<<actual<<" "<<(ok?"PASS":"FAIL")<<'\n';
    }
    const long long farePaise=1200;
    const bool exact50=canTravel(6200,farePaise);
    const bool below50=canTravel(6199,farePaise);
    long long bal=10000; const bool negativeRecharge=recharge(bal,-100);
    std::cout<<"balance leaves exactly Rs50: "<<(exact50?"PASS":"FAIL")<<'\n';
    std::cout<<"balance leaves Rs49.99: "<<(!below50?"PASS":"FAIL")<<'\n';
    std::cout<<"negative recharge rejected: "<<(!negativeRecharge && bal==10000?"PASS":"FAIL")<<'\n';
    std::cout<<"Five-trip hand total paise: "<<(1000+2000+3000+1200+2400)<<" (Rs 96.00)\n";
    const int passed=static_cast<int>(sizeof(tests)/sizeof(tests[0]))-failed + (exact50?1:0) + (!below50?1:0) + (!negativeRecharge && bal==10000?1:0);
    std::cout<<"Summary: "<<passed<<"/15 checks passed\n";
    return passed==15?0:1;
}
