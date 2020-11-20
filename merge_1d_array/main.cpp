#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
auto merge_1d_vect(const std::vector<T> &vect_1, const std::vector<T> &vect_2) -> std::vector<T> {
    std::vector<T> merged_vect;

    for (const auto &item : vect_1) {
        merged_vect.push_back(item);
    }

    for (const auto &item : vect_2) {
        merged_vect.push_back(item);
    }

    return merged_vect;
}

template <typename T>
auto print_1d_vect(const std::vector<T> &vect) {
    for (const auto &item : vect) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    const std::vector<char> xVect{
        {'A', 'B', 'C', 'D'}};

    const std::vector<char> yVect{
        {'E', 'F', 'G', 'H', 'I', 'J', 'K'}};

    std::cout << "Before Merged" << std::endl;

    std::cout << "xVect" << std::endl;
    print_1d_vect(xVect);
    std::cout << std::endl;

    std::cout << "yVect" << std::endl;
    print_1d_vect(yVect);
    std::cout << std::endl;

    const std::vector<char> mergedVect = merge_1d_vect(xVect, yVect);
    std::cout << "Merged" << std::endl;
    print_1d_vect(mergedVect);

    return 0;
}