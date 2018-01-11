#include <iostream>
#include <vector>

int main() {
    unsigned int n;
    int64_t sum = 0, average;
    std::cin >> n;
    std::vector<int> temperature(n);

    for (int& t : temperature) {
        std::cin >> t;
        sum += t;
    }

    average = sum / static_cast<int>(n);
    
    std::vector<int> ids;
    for (int i = 0; i < temperature.size(); i++) {
        if (temperature[i] > average) {
            ids.push_back(i);
        }
    }

    std::cout << ids.size() << std::endl;
    for (const auto& id : ids) {
        std::cout << id << " ";
    }
    return 0;
}
