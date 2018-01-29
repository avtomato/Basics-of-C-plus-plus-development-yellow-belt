#include <iostream>
#include <vector>
#include <algorithm>


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 3) {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it1 = std::begin(elements) + elements.size() / 3;
    auto it2 = it1 + elements.size() / 3;

    MergeSort(std::begin(elements), it1);
    MergeSort(it1, it2);
    MergeSort(it2, std::end(elements));

    std::vector<typename RandomIt::value_type> tmp;

    std::merge(std::begin(elements), it1, it1, it2, std::back_inserter(tmp));
    std::merge(tmp.begin(), tmp.end(), it2, std::end(elements), range_begin);
}

int main() {
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
