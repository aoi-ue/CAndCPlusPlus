//============================================================================
// Name        : CET113_QUIZ_04.cpp
// Author      : STANFORD
// Version     :
// Copyright   : Want to copy, don't copy blindly! Copy smartly!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Vector2
{
	static int counter;

	public:
	int x, y;

	Vector2():x(0), y(0)
	{
		cout << "default" << endl;
		++counter;
	}

	Vector2(int x, int y):x(0), y(0)
	{
		cout << "custom" << endl;
		++counter;
	}

	~Vector2()
	{
		cout << "destroy" << endl;
		--counter;
	}

	Vector2(const Vector2& copy): x(copy.x), y(copy.y)
	{
		cout << "copy" << endl;
		++counter;
	}

	Vector2& operator=(const Vector2& copy)
	{
		cout << "copy assign" << endl;
		return (*this);
	}

	Vector2& operator=(const Vector2 &&copy)
	{
		cout << "move assign" << endl;
		return (*this);
	}

	static int getCounter()
	{
		return counter;
	}
};

int Vector2::counter = 0;

Vector2 boo(Vector2 vec)
{
	cout << "boo" << endl;
	Vector2 temp;
	temp.x = vec.x;
	temp.y = vec.y;
	return temp;
}

void foo(Vector2& vec)
{
	cout << "foo" << endl;
	vec = boo(vec);
}

int main()
{
	Vector2 vecA;
	Vector2 vecB(1,2);
	Vector2 vecC = vecA;
	vecC = vecB;
	foo(vecC);

	cout << "total: " << Vector2::getCounter() << endl;
	return 0;
}
