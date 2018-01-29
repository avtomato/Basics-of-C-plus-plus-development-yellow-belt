#include <iostream>
#include <map>
#include <algorithm>


// если имя неизвестно, возвращает пустую строку
std::string FindNameByYear(const std::map<int, std::string>& names, int year) {
    std::string name;  // изначально имя неизвестно
    
    auto it = names.upper_bound(year);
    if (it != names.begin()) {
        name = std::prev(it) -> second;
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }
    std::string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const std::string first_name = FindNameByYear(first_names, year);
        const std::string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    return 0;
}
