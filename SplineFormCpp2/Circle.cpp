#include "stdafx.h"
#include "JillesSpline.h"
#include "MyForm.h"
#include <string>
#include "Circle.h"

Circle::Circle(System::Drawing::Point^ p, int radius)
{
	r = radius;
	point = p;


	//IsInside = ThisIsInSide(p, TheInstance);
};


bool Circle::ThisIsInSide(Point^ pt, Circle^ c)
{
	return Math::Pow(pt->X - c->x, 2) + Math::Pow(pt->Y - c->x, 2) < Math::Pow(c->x, 2);


};


