#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cmath>
using namespace std;

class Figure {
public:
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
};

class Rect : public Figure {
public:
  Rect(int width, int height) : width_(width), height_(height) {
  }

  string Name() const override { return "RECT"; }

  double Perimeter() const override {
    return 2 * (width_ + height_);
  }

  double Area() const override {
    return width_ * height_;
  }

private:
  int width_, height_;
};

class Triangle : public Figure {
public:
  Triangle(int side_one, int side_two, int side_three)
    : side_one_(side_one)
    , side_two_(side_two)
    , side_three_(side_three)
  {
  }

  string Name() const override { return "TRIANGLE"; }

  double Perimeter() const override {
    return side_one_ + side_two_ + side_three_;
  }

  double Area() const override {
    double p = Perimeter() / 2.0;
    return sqrt(p * (p - side_one_) * (p - side_two_) * (p - side_three_));
  }

private:
  int side_one_, side_two_, side_three_;
};

class Circle : public Figure {
public:
  Circle(double radius) : radius_(radius)
  {
  }

  string Name() const override { return "CIRCLE"; }

  double Perimeter() const override {
    return 2 * pi_ * radius_;
  }

  double Area() const override {
    return pi_ * radius_ * radius_;
  }

private:
  const double pi_ = 3.14;
  double radius_;
};

shared_ptr<Figure> CreateFigure(istream& input_stream) {
  string type;
  input_stream >> type;
  if (type == "RECT") {
    int width, height;
    input_stream >> width >> height;
    return make_shared<Rect>(width, height);
  } else if (type == "TRIANGLE") {
    int side_one, side_two, side_three;
    input_stream >> side_one >> side_two >> side_three;
    return make_shared<Triangle>(side_one, side_two, side_three);
  } else {
    int radius;
    input_stream >> radius;
    return make_shared<Circle>(radius);
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
