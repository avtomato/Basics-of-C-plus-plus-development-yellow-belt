#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::string> SplitIntoWords(const std::string& s) {
    std::vector<std::string> tmp;
    auto first_char = std::begin(s);
    for (auto it = std::begin(s); it != std::end(s); ++it) {
        if (*it == *std::find(it, std::end(s), ' ')) {
            tmp.push_back({first_char, it});
            first_char = ++it;
        }
    }
    tmp.push_back({first_char, std::end(s)});
    return tmp;
}

int main() {
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
