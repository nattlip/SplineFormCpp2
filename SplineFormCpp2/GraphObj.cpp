#include "stdafx.h"
#include "MyForm.h"
#include <string>
#include <algorithm>
#include "Circle.h"
#include <vector>


namespace SplineFormCpp2 {
	GraphObj::GraphObj()
	{

		Canvas = gcnew Bitmap(1200, 400);







		g = Graphics::FromImage(Canvas);


		g->Clear(Color::Yellow);






	}
};