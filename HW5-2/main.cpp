//
//  main.cpp
//  HW5-2
//
//  Created by Alyaev Roman on 11.03.2021.
//

#include <iostream>
#include <map>
#include <string>
#include <locale>

#include <boost/locale.hpp>

std::string locale_to_utf(const std::string & string)
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);
    std::locale locale = generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::to_utf<char> (string, locale);
}

std::string utf_to_locale(const std::string & string)
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);
    std::locale locale = generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::from_utf<char> (string, locale);
}

std::string func_hash(wchar_t letter)
{
    std::map<wchar_t, std::string> hash_letters =
    {
        {U'а',"a"},
        {U'б',"b"},
        {U'в',"v"},
        {U'г',"g"},
        {U'д',"d"},
        {U'е',"e"},
        {U'ё',"yo"},
        {U'ж',"zh"},
        {U'з',"z"},
        {U'и',"i"},
        {U'й',"y"},
        {U'к',"k"},
        {U'л',"l"},
        {U'м',"m"},
        {U'н',"n"},
        {U'о',"o"},
        {U'п',"p"},
        {U'р',"r"},
        {U'с',"s"},
        {U'т',"t"},
        {U'у',"u"},
        {U'ф',"f"},
        {U'х',"kh"},
        {U'ц',"c"},
        {U'ч',"ch"},
        {U'ш',"sh"},
        {U'щ',"sch"},
        {U'э',"e"},
        {U'ю',"yu"},
        {U'я',"ya"},
    };
    return hash_letters[letter];
}

int main()
{
    
    std::cout << "Hello, enter the russian text:" << std::endl;
    std::string text;
    std::cin >> text;
    std::cout << std::endl;

    std::string UTF8_text = locale_to_utf(text);
    std::u32string UTF32_text = boost::locale::conv::utf_to_utf<char32_t, char> (UTF8_text);
    std::u32string UTF32_text_copy = boost::locale::conv::utf_to_utf<char32_t, char> (UTF8_text);
        
    //здесь надо как-то реализовать сам транслит, пока что у меня не получается

    std::string UTF8_back = boost::locale::conv::utf_to_utf <char, char32_t> (UTF32_text);
    std::string text_back = utf_to_locale(UTF8_back);

    std::cout << "Your transliterated text:" << std::endl << text_back << std::endl;

    return 0;
}
