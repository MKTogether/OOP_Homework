#include <iostream>
#include <math.h>

using namespace std;

void sort(float *angle)
{
	for (int i = 0;i < 2;i++)
	{
		for (int j = 2 - i;j > 0;j--)
		{
			if (angle[j - 1] > angle[j])
			{
				angle[j] = angle[j] + angle[j - 1];
				angle[j - 1] = angle[j] - angle[j - 1];
				angle[j] = angle[j] - angle[j - 1];
			}
		}
	}
}

class Triangle
{

public:
	void Triangle_init(float f, float s, float t);
	bool Triangle_judge();
	float Triangle_perimeter();
	float Triangle_area();
	void Triangle_type();

private:
	float a;
	float b;
	float c;

};

void Triangle::Triangle_init(float f, float s, float t)
{
	a = f;
	b = s;
	c = t;
}

bool Triangle::Triangle_judge()
{
	if (a + b <= c || a + c <= b || b + c <= a)
		return 0;
	else
	{
		return 1;
	}
}

float Triangle::Triangle_perimeter()
{
	return a + b + c;
}

float Triangle::Triangle_area()
{
	float s, are;
	s = 0.5*(a + b + c);
	are = sqrt(s*(s - a)*(s - b)*(s - c));
	return are;
}

void Triangle::Triangle_type()
{
	float angle[3] = { a,b,c };
	sort(angle);
	if (angle[0] * angle[0] + angle[1] * angle[1] == angle[2] * angle[2])
		cout << "right triangle " << endl;
	else if (angle[0] * angle[0] + angle[1] * angle[1] > angle[2] * angle[2])
		cout << "acute triangle" << endl;
	else
		cout << "obtuse triangle" << endl;
}

int main()
{
	Triangle triangle1;
	triangle1.Triangle_init(6,6,6);

	if (triangle1.Triangle_judge())
	{
		cout << triangle1.Triangle_area() << endl;
		cout << triangle1.Triangle_perimeter() << endl;
		triangle1.Triangle_type();
	}
	else
		cout << "Can not form a triangle";
	system("pause");
	return 0;


}