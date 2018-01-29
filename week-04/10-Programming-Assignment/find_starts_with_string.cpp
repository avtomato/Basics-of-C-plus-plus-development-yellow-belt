#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const std::string& prefix) {
    return std::equal_range(range_begin,range_end,prefix, [&prefix](const std::string& a,const std::string& b) {
                                return a.compare(0, prefix.length(), b.substr(0, prefix.length())) < 0;
    });
};

int main() {
    const std::vector<std::string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
              (mt_result.second - begin(sorted_strings)) << std::endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    std::cout << (na_result.first - begin(sorted_strings)) << " " <<
              (na_result.second - begin(sorted_strings)) << std::endl;

    return 0;
}
