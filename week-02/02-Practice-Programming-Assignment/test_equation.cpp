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

int GetDistinctRealRootCount(double a, double b, double c) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestPositiveDiscriminant() {
    AssertEqual(GetDistinctRealRootCount(2, 5, 2), 2);
}

void TestEqualZeroDiscriminant() {
    AssertEqual(GetDistinctRealRootCount(2, 4, 2), 1);
}

void TestNegativeDiscriminant() {
    AssertEqual(GetDistinctRealRootCount(2, 1, 2), 0);
}

void TestLinearEquation() {
    AssertEqual(GetDistinctRealRootCount(0, 4, 10), 1);
}

void TestNoRoot() {
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0);
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestPositiveDiscriminant, "TestPositiveDiscriminant");
    runner.RunTest(TestEqualZeroDiscriminant, "TestEqualZeroDiscriminant");
    runner.RunTest(TestNegativeDiscriminant, "TestNegativeDiscriminant");
    runner.RunTest(TestLinearEquation, "TestLinearEquation");
    runner.RunTest(TestNoRoot, "TestNoRoot");
    return 0;
}
