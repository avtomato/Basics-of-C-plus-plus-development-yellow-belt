#include <iostream>
#include <deque>


enum class QueryType {
    Add,
    Sub,
    Mul,
    Div
};

struct Query {
    QueryType type;
    std::string value;
};

std::istream& operator >> (std::istream& is, Query& q) {
    std::string typeStr;
    is >> typeStr;
    if (typeStr == "+") {
        q.type = QueryType::Add;
        is >> q.value;
    } else if (typeStr == "-") {
        q.type = QueryType::Sub;
        is >> q.value;
    } else if (typeStr == "*") {
        q.type = QueryType::Mul;
        is >> q.value;
    } else if (typeStr == "/") {
        q.type = QueryType::Div;
        is >> q.value;
    }

    return is;
}

int main() {
    int x;
    std::cin >> x;

    int n;
    std::cin >> n;
    Query q;

    std::deque<std::string> d;
    d.push_back(std::to_string(x));

    for (int i = 0; i < n; ++i) {
        std::cin >> q;
        switch (q.type) {
            case QueryType::Add:
                d.push_front("(");
                d.push_back(")");
                d.push_back("+");
                d.push_back(q.value);
                break;
            case QueryType::Sub:
                d.push_front("(");
                d.push_back(")");
                d.push_back("-");
                d.push_back(q.value);
                break;
            case QueryType::Mul:
                d.push_front("(");
                d.push_back(")");
                d.push_back("*");
                d.push_back(q.value);
                break;
            case QueryType::Div:
                d.push_front("(");
                d.push_back(")");
                d.push_back("/");
                d.push_back(q.value);
                break;
        }
    }

    for (auto& item : d) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            std::cout << " " << item << " ";
        } else {
            std::cout << item;
        }
    }

    return 0;
}
