#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto to_upper(std::string& str) {
    auto f = [](unsigned char ch) -> unsigned char { return std::toupper(ch); };
    std::transform(str.begin(), str.end(), str.begin(), f);
}

auto to_lower(std::string& str) {
    auto f = [](unsigned char ch) -> unsigned char { return std::tolower(ch); };
    std::transform(str.begin(), str.end(), str.begin(), f);
}

auto main() -> int {
    std::string str("Example String");

    std::cout << "Original string: " << str << std::endl;

    to_upper(str);
    std::cout << "Uppercase string: " << str << std::endl;

    to_lower(str);
    std::cout << "Lowercase string: " << str << std::endl;

    return EXIT_SUCCESS;
}