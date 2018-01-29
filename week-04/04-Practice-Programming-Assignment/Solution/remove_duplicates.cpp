#include <algorithm>
using namespace std;

template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
  sort(begin(elements), end(elements));
  elements.erase(
      unique(begin(elements), end(elements)),
      elements.end());
}
