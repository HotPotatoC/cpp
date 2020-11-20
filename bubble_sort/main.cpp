#include <algorithm>
#include <array>
#include <iostream>

#ifndef MAX_LENGTH
#define MAX_LENGTH 6
#endif

auto bubble_sort(std::array<int, MAX_LENGTH> &base) {
    auto current = base.begin();
    auto previous = current++;
    while (current != base.end()) {
        if (*current < *previous) {
            std::swap(*current, *previous);
            current = base.begin();
        }
        previous = current++;
    }
}

auto iter_arr_out(const std::array<int, MAX_LENGTH> &base) {
    for (auto a : base)
        std::cout << a << " ";
    std::cout << "\n";
}

auto main() -> int {
    std::array<int, MAX_LENGTH> list{{5, 7, 2, 4, 1, 6}};

    std::cout << "Before sort: \n";
    iter_arr_out(list);

    std::cout << "After sort: \n";
    bubble_sort(list);
    iter_arr_out(list);

    return 0;
}