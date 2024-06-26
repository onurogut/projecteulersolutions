#include <iostream>
#include <vector>
#include <algorithm>

bool is_divisible(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % (i + 1) != 0) {
            return false;
        }
    }
    return true;
}

// Belirli bir uzunlukta ve hedef indekste bölünebilir dizi bulan fonksiyon
std::vector<int> find_divisible_range(int length, int target_index) {
    int count = 0;
    int start = 1;

    while (true) {
        std::vector<int> current_range(length);
        for (int i = 0; i < length; ++i) {
            current_range[i] = start + i;
        }

        do {
            if (is_divisible(current_range)) {
                ++count;
                if (count == target_index) {
                    return current_range;
                }
            }
        } while (std::next_permutation(current_range.begin(), current_range.end()));

        ++start;
    }
}

int main() {
    int length = 4;
    int target_index = 4;
    std::vector<int> result = find_divisible_range(length, target_index);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
