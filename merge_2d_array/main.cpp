#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
auto merge_2d_vect(const std::vector<std::vector<T>> &vect_1, const std::vector<std::vector<T>> &vect_2) -> std::vector<T> {
    std::vector<T> merged_vect;

    for (const auto &rows : vect_1) {
        for (const auto &item : rows) {
            merged_vect.push_back(item);
        }
    }

    for (const auto &rows : vect_2) {
        for (const auto &item : rows) {
            merged_vect.push_back(item);
        }
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

template <typename T>
auto print_2d_vect(const std::vector<T> &vect) {
    for (const auto &rows : vect) {
        for (const auto &item : rows) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    const std::vector<std::vector<char>> xVect{
        {'A', 'B'},
        {'C', 'D'},
        {'E', 'F'},
        {'G', 'H'}};

    const std::vector<std::vector<char>> yVect{
        {'I', 'J', 'K'}, {'L', 'M', 'N'}};

    std::cout << "Before Merged" << std::endl;

    std::cout << "xVect" << std::endl;
    print_2d_vect(xVect);
    std::cout << std::endl;

    std::cout << "yVect" << std::endl;
    print_2d_vect(yVect);
    std::cout << std::endl;

    const std::vector<char> mergedVect = merge_2d_vect(xVect, yVect);
    std::cout << "Merged" << std::endl;
    print_1d_vect(mergedVect);

    return 0;
}