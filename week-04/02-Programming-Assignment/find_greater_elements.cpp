#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
    auto it = std::find_if(std::begin(elements), std::end(elements), [border](const T& elem) {
        return elem > border;
    });
    std::vector<T> tmp;
    for (auto i = it; i != std::end(elements); ++i) {
        tmp.push_back(*i);
    }
    return tmp;
}

int main() {
    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::string to_find = "Python";
    std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
    return 0;
}
