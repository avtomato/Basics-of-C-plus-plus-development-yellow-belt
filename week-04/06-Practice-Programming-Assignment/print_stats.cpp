#include <iostream>
#include <vector>
#include <algorithm>


enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    std::nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person& lhs, const Person& rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}

void PrintStats(std::vector<Person> persons) {
    std::cout << "Median age = " << ComputeMedianAge(std::begin(persons), std::end(persons)) << std::endl;

    auto females = std::partition(std::begin(persons), std::end(persons), [](const Person& p) {
        return p.gender == Gender::FEMALE;
    });
    int median_females = ComputeMedianAge(std::begin(persons), females);

    auto employed_females = std::partition(std::begin(persons), females, [](const Person& p) {
        return p.is_employed;
    });
    int median_employed_females = ComputeMedianAge(std::begin(persons), employed_females);
    int median_unemployed_females = ComputeMedianAge(employed_females, females);


    auto males = std::partition(std::begin(persons), std::end(persons), [](const Person& p) {
        return p.gender == Gender::MALE;
    });
    int median_males = ComputeMedianAge(std::begin(persons), males);

    auto employed_males = std::partition(std::begin(persons), males, [](const Person& p) {
        return p.is_employed;
    });
    int median_employed_males = ComputeMedianAge(std::begin(persons), employed_males);
    int median_unemployed_males = ComputeMedianAge(employed_males, males);

    std::cout << "Median age for females = " << median_females << std::endl;
    std::cout << "Median age for males = " << median_males << std::endl;
    std::cout << "Median age for employed females = " << median_employed_females << std::endl;
    std::cout << "Median age for unemployed females = " << median_unemployed_females << std::endl;
    std::cout << "Median age for employed males = " << median_employed_males << std::endl;
    std::cout << "Median age for unemployed males = " << median_unemployed_males << std::endl;

}

int main() {
    std::vector<Person> persons = {
            {31, Gender::MALE, false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE, true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE, false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
