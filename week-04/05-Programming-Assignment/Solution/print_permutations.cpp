#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int range_length;
  cin >> range_length;
  vector<int> permutation(range_length);
  
  // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
  // Заполняет диапазон последовательно возрастающими значениями
  iota(permutation.begin(), permutation.end(), 1);
  
  // reverse          -> http://ru.cppreference.com/w/cpp/algorithm/reverse
  // Меняет порядок следования элементов в диапазоне на противоположный
  reverse(permutation.begin(), permutation.end());
  
  // prev_permutation ->
  //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
  // Преобразует диапазон в предыдущую (лексикографически) перестановку,
  // если она существует, и возвращает true,
  // иначе (если не существует) - в последнюю (наибольшую) и возвращает false
  do {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  } while (prev_permutation(permutation.begin(), permutation.end()));

  return 0;
}
