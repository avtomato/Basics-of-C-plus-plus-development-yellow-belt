#### Задание по программированию: Наследование своими руками ####


Дан следующий код:
```objectivec
#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код

    const string Name;
};


class Dog {
public:
    // ваш код

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
```
Определите до конца тела классов, соблюдая следующие требования:

1. Класс *Dog* должен являться наследником класса *Animal*.
2. Конструктор класса *Dog* должен принимать параметр типа *string* и инициализировать им поле *Name* в классе *Animal*.