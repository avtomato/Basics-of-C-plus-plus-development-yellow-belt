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

bool IsPalindrom(const std::string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestOddLengthStringTrue1() {
    AssertEqual(IsPalindrom("madam"), true);
}

void TestOddLengthStringTrue2() {
    AssertEqual(IsPalindrom("level"), true);
}

void TestOddLengthStringTrue3() {
    AssertEqual(IsPalindrom("wasitacaroracatisaw"), true);
}

void TestOddLengthStringFalse1() {
    AssertEqual(IsPalindrom("gentleman"), false);
}
// 11
void TestOddLengthStringFalse2() {
    AssertEqual(IsPalindrom("abcca"), false);
}
// 12
void TestOddLengthStringFalse3() {
    AssertEqual(IsPalindrom("abcbc"), false);
}

void TestEvenLengthStringTrue() {
    AssertEqual(IsPalindrom("abba"), true);
}
// 4
void TestEvenLengthStringFalse() {
    AssertEqual(IsPalindrom("ab"), false);
}

void TestLongString1() {
    AssertEqual(IsPalindrom("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"), true);
}

void TestLongString2() {
    AssertEqual(IsPalindrom("abcdefghijklnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"), false);
}

void TestUpperCase() {
    AssertEqual(IsPalindrom("aA"), false);
}

void TestPassFirstSymbol() {
    AssertEqual(IsPalindrom("asitacaroracatisaw"), false);
}

void TestPassLastSymbol() {
    AssertEqual(IsPalindrom("wasitacaroracatisa"), false);
}

void TestPassTwoFirstSymbol() {
    AssertEqual(IsPalindrom("sitacaroracatisaw"), false);
}

void TestPassTwoLastSymbol() {
    AssertEqual(IsPalindrom("wasitacaroracatis"), false);
}

void TestEmptyString() {
    AssertEqual(IsPalindrom(""), true);
}
// 2
void TestOneSymbolString() {
    AssertEqual(IsPalindrom("a"), true);
}

void TestSpaceSymbols() {
    AssertEqual(IsPalindrom("kay ak"), false);
}

void TestTabSymbols() {
    AssertEqual(IsPalindrom("kay\tak"), false);
}

void TestIndent() {
    AssertEqual(IsPalindrom(" kayak"), false);
}

void TestWhitespaceSymbols() {
    AssertEqual(IsPalindrom("\t\n  \n\t"), true);
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestOddLengthStringTrue1, "TestOddLengthStringTrue1");
    runner.RunTest(TestOddLengthStringTrue2, "TestOddLengthStringTrue2");
    runner.RunTest(TestOddLengthStringTrue3, "TestOddLengthStringTrue3");
    runner.RunTest(TestOddLengthStringFalse1, "TestOddLengthStringFalse1");
    runner.RunTest(TestOddLengthStringFalse2, "TestOddLengthStringFalse2");
    runner.RunTest(TestOddLengthStringFalse3, "TestOddLengthStringFalse3");
    runner.RunTest(TestEvenLengthStringTrue, "TestEvenLengthStringTrue");
    runner.RunTest(TestEvenLengthStringFalse, "TestEvenLengthStringFalse");
    runner.RunTest(TestLongString1, "TestLongString1");
    runner.RunTest(TestLongString2, "TestLongString2");
    runner.RunTest(TestUpperCase, "TestUpperCase");
    runner.RunTest(TestPassFirstSymbol, "TestPassFirstSymbol");
    runner.RunTest(TestPassLastSymbol, "TestPassLastSymbol");
    runner.RunTest(TestPassTwoFirstSymbol, "TestPassTwoFirstSymbol");
    runner.RunTest(TestPassTwoLastSymbol, "TestPassTwoLastSymbol");
    runner.RunTest(TestEmptyString, "TestEmptyString");
    runner.RunTest(TestOneSymbolString, "TestOneSymbolString");
    runner.RunTest(TestSpaceSymbols, "TestSpaceSymbols");
    runner.RunTest(TestTabSymbols, "TestTabSymbols");
    runner.RunTest(TestIndent, "TestIndent");
    runner.RunTest(TestWhitespaceSymbols, "TestWhitespaceSymbols");
    return 0;
}

