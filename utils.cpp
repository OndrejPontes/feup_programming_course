#include "utils.h"

std::vector<int> getNumbersFromUser()
{
    std::string text;
    std::getline(std::cin, text);
	
    const std::regex delimiters("[^\\s.,-:;!?]+");
    std::vector<int> result;
    int x;

    auto words_begin = std::sregex_iterator(text.begin(), text.end(), delimiters);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::istringstream((*i).str()) >> x;
        result.push_back(x);
    }
    return result;
}
