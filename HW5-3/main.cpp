//
//  main.cpp
//  HW5-3
//
//  Created by Alyaev Roman on 11.03.2021.
//

#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main(int argc, const char * argv[])
{
    std::string test_text = "TerMinaTorT800@meme.com is a person who loves James Cameron's films, but there is also an absolutelyNormal@gmail.ru who always forget that Google use .COM; on the other side we have 1L0v3c++@fail.yo. He is actually a strange man that can't understand regex";

    std::regex email_pattern(R"(((([0-9|A-Z|a-z]+))@([A-Z|a-z]+\.){1,2}([A-Z|a-z]{2,}))*)");

    std::sregex_iterator begin(test_text.cbegin(), test_text.cend(), email_pattern);
    std::sregex_iterator end;

    std::for_each(begin, end, [](const std::smatch & m){std::cout << m[0] << " - " << m[4] << m[5] << " ";});

    return 0;
}

