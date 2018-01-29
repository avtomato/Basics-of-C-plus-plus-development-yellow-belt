#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        input[i] = i + 1;
    }

    std::vector<std::vector<int>> output;
    do {
        output.push_back({std::begin(input), std::end(input)});
    } while(std::next_permutation(std::begin(input), std::end(input)));

    std::reverse(std::begin(output), std::end(output));
    for (auto& vector : output) {
        for (auto& i : vector) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
