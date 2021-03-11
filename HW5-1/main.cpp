#include <iostream>
#include <codecvt>
#include <locale>
#include <iomanip>

using namespace std;

int main() {
    
    std::locale locale_rus("ru_RU.UTF-8");
    std::locale locale_de("de_DE.UTF-8");
    
    double amount_of_euro;
    std::cout << "Hello, insert the amount of euro: ";
    
    std::cin.imbue(locale_de);
    std::cin >> amount_of_euro;
    
    auto amount_of_rubles = amount_of_euro * 87.85;
    
    std::cout.imbue(locale_de);
    std::cout << std::endl << amount_of_euro << " EUR = ";
    
    std::cout.imbue(locale_rus);
    std::cout << amount_of_rubles << " RUB" << std::endl;
    
    return 0;
}
