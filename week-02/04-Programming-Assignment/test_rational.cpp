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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void TestRational() {
    const Rational r(3, 10);
    AssertEqual(r.Numerator(), 3);
    AssertEqual(r.Denominator(), 10);
}

void TestTruncateRational() {
    const Rational r(8, 12);
    AssertEqual(r.Numerator(), 2);
    AssertEqual(r.Denominator(), 3);
}

void TestNegativeNumenator() {
    const Rational r(-4, 6);
    AssertEqual(r.Numerator(), -2);
    AssertEqual(r.Denominator(), 3);
}

void TestNegativeDenominator() {
    const Rational r(4, -6);
    AssertEqual(r.Numerator(), -2);
    AssertEqual(r.Denominator(), 3);
}

void TestBothNegative() {
    const Rational r(-2, -3);
    AssertEqual(r.Numerator(), 2);
    AssertEqual(r.Denominator(), 3);
}

void TestZeroNumenator() {
    const Rational r(0, 15);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestDefaultConstructed() {
    Rational r = Rational();
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestRational, "TestRational");
  runner.RunTest(TestTruncateRational, "TestTruncateRational");
  runner.RunTest(TestNegativeNumenator, "TestNegativeNumenator");
  runner.RunTest(TestNegativeDenominator, "TestNegativeDenominator");
  runner.RunTest(TestBothNegative, "TestBothNegative");
  runner.RunTest(TestZeroNumenator, "TestZeroNumenator");
  runner.RunTest(TestDefaultConstructed, "TestDefaultConstructed");
  return 0;
}
