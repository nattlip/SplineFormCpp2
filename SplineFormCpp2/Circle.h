#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Collections;







public ref class Circle
{
public:


	Circle(Point^ p, int r);
	property int x;
	property int y;
	property int r;
	property bool IsInside;
	property Point^  point;
	bool ThisIsInSide(Point^ pt, Circle^ c);

};

