#### Задание по программированию: Реализовать функции, объявленные в заголовочном файле ####


Вам дан заголовочный файл *sum_reverse_sort.h*, содержащий объявления трёх функций

[sum_reverse_sort.h](https://github.com/avtomato/Basics-of-C-plus-plus-development-yellow-belt/blob/master/week-03/01-Programming-Assignment/Source/sum_reverse_sort.h)

```objectivec
#pragma once
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);

```
Вам надо прислать *cpp*-файл, содержащий определения этих функций.

##### Как будет тестироваться ваш код #####
Автоматическая тестирующая система добавит ваш *cpp*-файл в проект, содержащий другой *cpp*-файл с юнит-тестами для всех трёх функций, а также файл *sum_reverse_sort.h*. Затем она соберёт этот проект и, если компиляция будет выполнена успешно, запустит получившийся исполняемый файл. Если он завершится успешно (т. е. юнит-тесты не найдут ошибок в вашей реализации), то ваша посылка будет засчитана.
