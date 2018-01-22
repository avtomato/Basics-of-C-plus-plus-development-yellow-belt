//
// Created by avtomato on 1/8/18.
//

#include <algorithm>

#include <sum_reverse_sort.h>


int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    string tmp = "";
    for (size_t k = s.length(); k > 0; --k) {
        size_t i = k - 1;
        tmp += s[i];
    }
    return tmp;
}

void Sort(vector<int>& nums) {
    sort(begin(nums), end(nums));
}
