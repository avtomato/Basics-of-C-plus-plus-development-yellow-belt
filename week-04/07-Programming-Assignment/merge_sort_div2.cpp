#include <iostream>
#include <vector>
#include <algorithm>


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it = std::begin(elements) + elements.size() / 2;
    MergeSort(std::begin(elements), it);
    MergeSort(it, std::end(elements));
    std::merge(std::begin(elements), it, it, std::end(elements), range_begin);
}

int main() {
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
