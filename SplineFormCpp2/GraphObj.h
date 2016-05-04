#pragma once


using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Collections;

namespace SplineFormCpp2 {
public	ref class GraphObj
	{
	public:

		property Bitmap^  Canvas;   // bitmap to draw to in memory instantiated with width and height
		property Graphics^ g;      // graphics to draw to 
		GraphObj();


	};

};