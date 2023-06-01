#include <iostream>
using namespace std;

class Rectangle {
protected:
    double length;  // длина прямоугольника
    double width;   // ширина прямоугольника

public:
    Rectangle(double length, double width)
        : length(length), width(width) {}

    double getArea() const {
        return length * width;  // вычисление площади прямоугольника
    }

    virtual void print() const {
        cout << "Rectangle: Length = " << length << ", Width = " << width << ", Area = " << getArea() << endl;
        // вывод информации о прямоугольнике
    }
};

class RectangularCuboid : public Rectangle {
private:
    double height;  // высота прямоугольного параллелепипеда

public:
    RectangularCuboid(double length, double width, double height)
        : Rectangle(length, width), height(height) {}

    double getVolume() const {
        return getArea() * height;  // вычисление объема прямоугольного параллелепипеда
    }

    void print() const override {
        cout << "Rectangular Cuboid: Length = " << length << ", Width = " << width << ", Height = " << height << ", Volume = " << getVolume() << endl;
        // вывод информации о прямоугольном параллелепипеде
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);   // создание объекта прямоугольника
    RectangularCuboid rectangularCuboid(4.0, 6.0, 2.0);   // создание объекта прямоугольного параллелепипеда

    Rectangle* rectanglePtr = &rectangle;   // указатель на базовый класс Rectangle, указывающий на объект прямоугольника
    RectangularCuboid* rectangularCuboidPtr = &rectangularCuboid;   // указатель на производный класс RectangularCuboid, указывающий на объект прямоугольного параллелепипеда

    rectanglePtr->print();   // вызов метода print() для объекта прямоугольника с использованием указателя на базовый класс
    rectangularCuboidPtr->print();   // вызов метода print() для объекта прямоугольного параллелепипеда с использованием указателя на производный класс

    return 0;
}
