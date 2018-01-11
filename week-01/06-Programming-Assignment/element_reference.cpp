#include <iostream>
#include <map>


template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, Key key) {
    try {
        return m.at(key);
    } catch (const std::out_of_range& oor) {
        throw std::runtime_error("Out of Range error");
    }
}


int main() {
    std::map<int, std::string> m = {{0, "value"}};
    std::string& item = GetRefStrict(m, 0);
    item = "newvalue";
    std::cout << m[0] << std::endl; // выведет newvalue

    return 0;
}
