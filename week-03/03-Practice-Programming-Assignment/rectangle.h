//
// Created by avtomato on 1/8/18.
//

#ifndef COURSERA_RECTANGLE_H
#define COURSERA_RECTANGLE_H

#endif //COURSERA_RECTANGLE_H
#pragma once


class Rectangle {
public:
    explicit Rectangle(int width, int height);


    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;
};
