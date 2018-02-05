#include <iostream>

using namespace std;


class Animal {
public:
    // ваш код
    Animal(const string& name = "animal") : Name(name) {}

    const string Name;
};


class Dog : public Animal {
public:
    // ваш код
    Dog(const string& name = "dog") : Animal(name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main() {
    
    return 0;
}
