#include <iostream> 

// class shape 
class Shape { 
    virtual float GetArea() { return 0; }; 
}; 

// class recentagle 
class Rectangle: public Shape {
    public: 
        Rectangle(float width, float height): _width(width), _height (height){}; 
        float GetArea() {return _width *_height; };

    private: 
        float _width; 
        float _height; 

}; 
// class square 
class Square: public Rectangle {
    public: 
        Square(float _length): Rectangle(_length, _length) {}; 

};


int main () {
    Square s(5); 
    Rectangle r(3,4); 
    std::cout << s.GetArea() << r.GetArea(); 
}
