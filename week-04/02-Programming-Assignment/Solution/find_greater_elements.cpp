#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  // Начнём итерироваться по множеству
  auto it = begin(elements);
  // Цель — найти первый элемент, больший border
  // Если итератор не достиг конца и указывает не туда, двигаем
  while (it != end(elements) && *it <= border) {
  	++it;
  }
  // Возвращаем вектор, созданный из элементов множества, начиная с it
  return {it, end(elements)};
}
