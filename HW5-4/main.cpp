//
//  main.cpp
//  HW5-4
//
//  Created by Alyaev Roman on 11.03.2021.
//

#include <iostream>
#include <iomanip>
#include <regex>
#include <string>

int main(int argc, const char * argv[])
{
    std::regex date_pattern(R"(([0-3]{1}[0-1]{1}|[0-2]{1}[0-9]{1})\.(0{1}[1-9]{1}|1{1}[0-2]{1})\.([0-9]{4})+)");
    
    std::regex time_pattern(R"(([0-1]{1}[0-9]{1}|2{1}[0-4]{1})\.([0-5]{1}[0-9]{1})\.([0-5]{1}[0-9]{1})([^[:digit:]]))");
    
    std::string test_text = "Once upon a time (if you would like to now - 17.01.2077 at 4 p.m. = 16.00.00) a little stranger came to a cyber-saloon to upgrade saw-looked rail-gun 20012.123.45 v5.0 , but he was outsourced on the next day on 18.01.2077 at 12.04.53 (DO NOT MISS 05.12.77) :C He returned some time later and got his success on 08.03.2079 C: (actually it was at 10.05.58)";
    
    std::sregex_iterator begin1(test_text.begin(), test_text.end(), date_pattern);
    std::sregex_iterator end1;
    
    std::cout << "Dates: (DD:MM:YYYY)" << std::endl;
    std::for_each(begin1, end1, [](const std::smatch & m){std::cout << m[0] << std::endl;});
    
    std::sregex_iterator begin2(test_text.begin(), test_text.end(), time_pattern);
    std::sregex_iterator end2;

    std::cout << "Times: (HH:MM:SS)" << std::endl;
    std::for_each(begin2, end2, [](const std::smatch & m){std::cout << m[1] << '.' << m[2] << '.' << m[3] << std::endl;});
    
    return 0;
}
