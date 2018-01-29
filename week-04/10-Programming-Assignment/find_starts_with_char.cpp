#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {

    std::string target1 = {prefix};
    auto first = std::lower_bound(range_begin, range_end, target1);

    auto next = static_cast<char>(prefix + 1);
    std::string target2 = {next};
    auto last = std::upper_bound(range_begin, range_end, target2);

    return std::make_pair(first, last);
};

int main() {
    const std::vector<std::string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    std::cout << (p_result.first - begin(sorted_strings)) << " " <<
              (p_result.second - begin(sorted_strings)) << std::endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    std::cout << (z_result.first - begin(sorted_strings)) << " " <<
              (z_result.second - begin(sorted_strings)) << std::endl;

    return 0;
}
