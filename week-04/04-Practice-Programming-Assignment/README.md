#### Тренировочное задание по программированию: Удаление повторов ####


Напишите шаблонную функцию *RemoveDuplicates*, принимающую по ссылке вектор *elements* объектов типа *T* и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.

Гарантируется, что объекты типа *T* можно сравнивать с помощью операторов ==, !=, < и >.
```objectivec
template <typename T>
void RemoveDuplicates(vector<T>& elements);
```
##### Пример кода #####
```objectivec
int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
```
###### Вывод ######
```commandline
6 4 7 0 1
C++ C
```
Порядок элементов может быть другим, например:
```commandline
7 4 6 1 0
C C++
```