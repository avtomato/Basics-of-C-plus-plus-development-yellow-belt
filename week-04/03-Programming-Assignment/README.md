#### Задание по программированию: Разбиение на слова ####


Напишите функцию *SplitIntoWords*, разбивающую строку на слова по пробелам.
```objectivec
vector<string> SplitIntoWords(const string& s);
```
Гарантируется, что:
* строка непуста;
* строка состоит лишь из латинских букв и пробелов;
* первый и последний символы строки не являются пробелами;
* строка не содержит двух пробелов подряд.

##### Подсказка #####
Рекомендуется следующий способ решения задачи:
* искать очередной пробел с помощью алгоритма find;
* создавать очередное слово с помощью конструктора строки по двум итераторам.

##### Пример кода #####
```objectivec
int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
```
###### Вывод ######
```commandline
 С/Cpp/Java/Python
```