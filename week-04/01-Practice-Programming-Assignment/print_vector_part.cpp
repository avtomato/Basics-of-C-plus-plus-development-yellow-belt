#include <iostream>
#include <vector>
#include <algorithm>


void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = std::find_if(std::begin(numbers), std::end(numbers), [](const int& num) {
        return num < 0;
    });
    while (it-- != std::begin(numbers)) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  PrintVectorPart({6, 1, 8, 5, 4});
  return 0;
}
