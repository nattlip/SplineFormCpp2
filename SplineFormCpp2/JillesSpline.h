#pragma once


//  included to let compiler see circle
#include "Circle.h"
#include "ClassesAndStructures.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Collections;

namespace SplineFormCpp2 {

	public ref  class JillesSpline
	{
	public:




		property int JillesSpline::xaxis0;
		property int  yaxis0;
		property int xaxislength;
		property int yaxislength;
		property int indexy;

		double h = 15;
		double w;
		double dp;

		property double  pairsymax;

		property List<Circle^>^ circles;
		 List<Circle^>^ bezcircles = gcnew List<Circle^>();

		 property Graphics^ gap;


		// constructor body in pcc file
		JillesSpline(Graphics^ ge, System::Drawing::Size s, int p);

		void DrawXaxis();
		void DrawYaxis();
		void DrawStart(List<KeyValuePair<String^, double>>^ pairs);
		void DrawChart(List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles);
		void DrawCurve( List<Circle^>^ circles);
		void CreateChartControlCircles(List<Circle^>^ circles);  // to create chartbezier=control circles
		void DrawSpline(List<Circle^>^ circles);
		void DrawChartCircles( List<Circle^>^ circles);
		void DrawXaxisMarksAndLegenda( List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles);
		void DrawYaxisMarksAndLegenda( List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles);
		void DrawCircle( Point^ po, Drawing::Color co);
	};
}