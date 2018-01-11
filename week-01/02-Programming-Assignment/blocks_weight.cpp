#include <iostream>

int main() {
    unsigned int n, r;
    std::cin >> n >> r;
    uint64_t w, h, d;
    uint64_t s = 0, m;

    for (int i = 0; i < n; ++i) {
        std::cin >> w >> h >> d;
        m = w * h * d * r;
        s += m;
    }
    std::cout << s;
    return 0;
}
