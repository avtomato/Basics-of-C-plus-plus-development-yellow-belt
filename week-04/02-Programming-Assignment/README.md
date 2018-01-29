#### Задание по программированию: Часть множества ####


Напишите шаблонную функцию *FindGreaterElements*, принимающую множество *elements* объектов типа *T* и ещё один объект *border* типа *T* и возвращающую вектор из всех элементов множества, бо́льших *border*, в возрастающем порядке.
```objectivec
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);
```
##### Пример кода #####
```objectivec
int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
```
###### Вывод ######
```commandline
7 8
0
```