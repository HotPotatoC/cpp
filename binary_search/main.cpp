#include <array>
#include <iostream>

#ifndef MAX_LENGTH
#define MAX_LENGTH 6
#endif

auto binary_search(const std::array<int, MAX_LENGTH> &base, const int left, const int right, const int x) {
    if (left <= right) {
        auto mid = left + (right - left) / 2;

        if (base[mid] == x) {
            return mid;
        }

        if (base[mid] > x) {
            return binary_search(base, left, mid - 1, x);
        } else {
            return binary_search(base, mid + 1, right, x);
        }
    }

    return -1;
}

auto iter_arr_out(const std::array<int, MAX_LENGTH> &base) {
    for (auto a : base)
        std::cout << a << " ";
    std::cout << "\n";
}

auto main() -> int {
    std::array<int, MAX_LENGTH> list{
        {5, 8, 9, 11, 24, 31}};

    std::cout << "Array: ";
    iter_arr_out(list);
    std::cout << std::endl;

    const int search = 11;
    const int result = binary_search(list, 0, MAX_LENGTH - 1, search);

    if (result == -1) {
        std::cout << "Did not find item " << search << " in the array";
        return 0;
    }

    std::cout << "Found item " << search << " at index: " << result << std::endl;

    return 0;
}