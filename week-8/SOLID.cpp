/******************************************************************************
filename SOLID.cpp
author Lian Yuhan
email yuhan.lian@digipen.edu
date created 22 October 2019
Brief Description: Exercise to rework code to satisfy SOLID
******************************************************************************/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

enum PRINT_STYLE
{
    STYLE_A,
    STYLE_B,
    STYLE_C
};

class Shape 
{ 
    public: 
        virtual PRINT_STYLE GetStyle() const {return PRINT_STYLE::STYLE_A; };  
        virtual float GetArea() const { return 0; };
}; 

class ShapePrinter 
{
    public: 
        void Print(const Shape& shape) const; 
}; 

void ShapePrinter::Print(const Shape& shape) const 
{
    switch (shape.GetStyle())
    {
    case STYLE_A:
        cout << "A: The area is " << shape.GetArea() << endl;
        break;

    case STYLE_B:
        cout << "B: The given shape has an area of " << shape.GetArea() << endl;
        break;

    case STYLE_C:
        cout << "C: Answer: " << shape.GetArea() << endl;
        break;
        
    default:
        cout << "A: The area is " << shape.GetArea() << endl;
        break;
    }
}

class Rectangle: public Shape 
{
    public: 
        Rectangle(float width, float height): _width(width), _height(height){}; 
        float GetArea() const {return _width *_height; };

    private: 
        float _width; 
        float _height; 
}; 

class Triangle: public Shape{
    public: 
        Triangle(float width, float height): _width(width), _height(height){}; 
        float GetArea() const {return 0.5f *_width *_height; };
        PRINT_STYLE GetStyle() const {return PRINT_STYLE::STYLE_C; }; 
        
    private: 
        float _width; 
        float _height; 
};

class Square: public Rectangle 
{
    public: 
        Square(float _width): Rectangle(_width, _width) {}; 
        PRINT_STYLE GetStyle() const {return PRINT_STYLE::STYLE_B; }; 
};

class Circle: public Shape 
{
    public: 
        Circle(float width): _width(width){}; 
        float GetArea() const {return (float)M_PI  *_width *_width; };

    private: 
        float _width; 
}; 

int main() 
{
    Rectangle r(10,5);
    Square s(7);
    Triangle t(10,5);  
    Circle c(4);

    ShapePrinter print; 

    print.Print(r);
    print.Print(s);
    print.Print(t);
    print.Print(c);
}
