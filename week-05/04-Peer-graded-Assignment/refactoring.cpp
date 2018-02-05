#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    Person(const string& name, const string& occupation) : _name(name), _occupation(occupation) {}

    string GetName() const {
        return _name;
    }
    string GetOccupation() const {
        return _occupation;
    }
    virtual void Walk(const string& destination) const = 0;

private:
    const string _name;
    const string _occupation;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) : Person(name, "Student"), _favouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << _favouriteSong << endl;
    }

private:
    const string _favouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), _subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << _subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

private:
    const string _subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(Person& person) const {
        cout << "Policeman: " << GetName() << " checks " << person.GetOccupation() << ". "
             << person.GetOccupation() << "'s name is: " << person.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }
};


void VisitPlaces(Person& person, vector<string> places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
