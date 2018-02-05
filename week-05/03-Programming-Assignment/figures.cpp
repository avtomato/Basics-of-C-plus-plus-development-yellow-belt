#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;


class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const double& a, const double& b, const double& c) : a_(a), b_(b), c_(c) {}

    string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return a_ + b_ + c_;
    }
    double Area() const override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    double a_, b_, c_;
};

class Rect : public Figure {
public:
    Rect(const double& width, const double& height) : width_(width), height_(height) {}

    string Name() const override {
        return "RECT";
    }
    double Perimeter() const override {
        return (width_ + height_) * 2;
    }
    double Area() const override {
        return width_ * height_;
    }

private:
    double width_, height_;
};

class Circle : public Figure {
public:
    Circle(const double& r) : r_(r) {}

    string Name() const override {
        return "CIRCLE";
    }
    double Perimeter() const override {
        return 2 * 3.14 * r_;
    }
    double Area() const override {
        return 3.14 * r_ * r_;
    }

private:
    double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string typeStr;
    is >> typeStr;
    if (typeStr == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if  (typeStr == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }

}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
