#include <iostream>
#include <sstream>


template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
    if (t != u) {
        std::ostringstream os;
        os << " AssertionError: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << " PASSED: " << test_name << std::endl;
        } catch (std::exception& e) {
            ++fail_count;
            std::cerr << " FAIL: " << test_name << e.what() << std::endl;
        } catch (...) {
            ++fail_count;
            std::cerr << "Unknown exception caught" << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << "----------------------------------------------------------------------" << std::endl;
            std::cerr << "FAILED (failures=" << fail_count << ")" << std::endl;
            exit(1);
        } else {
            std::cerr << "----------------------------------------------------------------------" << std::endl;
            std::cerr << "OK" << std::endl;
        }
    }

private:
    int fail_count = 0;
};

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

void TestIncognito() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1900), "Incognito");
}

void TestUnknownLastName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1965), "Polina with unknown last name");
}

void TestBothName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1990), "Polina Sergeeva");
}

void TestSaveFirstName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual(person.GetFullName(1969), "Polina Sergeeva");
}

void TestChangeFirstName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");
}

void TestChangeLastName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    person.ChangeFirstName(1970, "Appolinaria");
    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1969), "Polina Volkova");
}

void TestChangeBothName() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    person.ChangeFirstName(1970, "Appolinaria");
    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1970), "Appolinaria Volkova");
}

void TestUnknownFirstName() {
    Person person;
    person.ChangeLastName(1967, "Sergeeva");
    person.ChangeFirstName(1995, "Polina");
    AssertEqual(person.GetFullName(1970), "Sergeeva with unknown first name");
}


int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestIncognito, "TestIncognito");
    runner.RunTest(TestUnknownLastName, "TestUnknownLastName");
    runner.RunTest(TestUnknownFirstName, "TestUnknownFirstName");
    runner.RunTest(TestBothName, "TestBothName");
    runner.RunTest(TestSaveFirstName, "TestSaveFirstName");
    runner.RunTest(TestChangeFirstName, "TestChangeFirstName");
    runner.RunTest(TestChangeLastName, "TestChangeLastName");
    runner.RunTest(TestChangeBothName, "TestChangeBothName");
    return 0;
}

