//#include "ClassesAndStructures.h"
#include "stdafx.h"
#include "MyForm.h"
#include <string>
#include <algorithm>
#include "Circle.h"
#include <vector>
#include "GraphObj.h"

namespace SplineFormCpp2 {
	//using namespace System::Collections::Generic;

	JillesSpline::JillesSpline(Graphics^ ga,System::Drawing::Size s, int padding)
	{
		h = s.Height;
		w = s.Width;
		dp = padding;



		JillesSpline::xaxis0 = h - ((dp / 100)*h);
		JillesSpline::yaxis0 = (dp / 100) * w;
		JillesSpline::xaxislength = w - dp / 100 * w;
		JillesSpline::yaxislength = h - dp / 100 * h;

		JillesSpline::gap = ga;
			
		Graphics^ temp = ga;


	}






	void  JillesSpline::DrawXaxis(){

		Pen^ myPen = gcnew Pen(Color::Red);
		
		//http://social.msdn.microsoft.com/Forums/en-US/dcc8228d-6937-450d-b4e2-e833fb1f388b/access-a-forms-public-functions-from-a-global-function-in-a-different-file?forum=Vsexpressvc
			
		gap->DrawLine(myPen, yaxis0, xaxis0, yaxis0+xaxislength, xaxis0);
		DrawCircle(Point(yaxis0 + xaxislength, xaxis0),Color::Black);
		delete myPen;
	

	}

	void  JillesSpline::DrawYaxis(){

		Pen^ myPen = gcnew Pen(Color::Red);
		//http://social.msdn.microsoft.com/Forums/en-US/dcc8228d-6937-450d-b4e2-e833fb1f388b/access-a-forms-public-functions-from-a-global-function-in-a-different-file?forum=Vsexpressvc
	
		gap->DrawLine(myPen, yaxis0, 0, yaxis0, yaxislength);
		delete myPen;
	

	}

	void  JillesSpline::DrawStart(System::Collections::Generic::List<KeyValuePair<String^, double>>^ pairs)
	{

		//Generic::List<KeyValuePair<String^, Double>>^ n = gcnew Generic::List<KeyValuePair<String^, Double>>();

		const int l = 24; //pairs->Count;
		//http://msdn.microsoft.com/en-us/library/bb983093.aspx

		array< Double, l - 1>^ pairsy;
		double pairsy1[l];


		int deltapointx = (xaxislength / (l-1));

		

		for (int i = 0; i < l; i++)
		{

			pairsy1[i] = pairs[i].Value;

		};
		//http://www.cplusplus.com/reference/algorithm/max_element/
		pairsymax = *std::max_element(pairsy1, pairsy1 + l);

		indexy =  (h / 2) / pairsymax;

		double indexyfloat = indexy;

		if (std::isnan(indexyfloat))
		{
			indexyfloat = 0;
		}

		List<Circle^>^ circles = gcnew List<Circle^>;

		for (int i = 0; i < l; i++)
		{

			Point^ charpoint = gcnew Point;

			charpoint->X = yaxis0 + i * deltapointx;
			charpoint->Y = xaxis0 - pairs[i].Value * indexy;

			Circle^ charcircle = gcnew Circle(charpoint, 3);

			 circles->Add(charcircle);


		};


		DrawChart( pairs, circles);

	}

	void  JillesSpline::DrawChart(List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles)
	{

	

		gap->Clear(Color::WhiteSmoke);


		DrawXaxis();
		DrawYaxis();


		//DrawCurve(circles);
		CreateChartControlCircles(circles);
		DrawSpline( circles);
		DrawChartCircles(circles);
		DrawXaxisMarksAndLegenda(pairs, circles);
		DrawYaxisMarksAndLegenda(pairs, circles);
	}

	void JillesSpline::DrawCurve(List<Circle^>^ circles)
	{
	
	
		List<Point>^ pointlist = gcnew List<Point>;
	
		for each(Circle^ c in circles)
		{

			//Point^ charpoint = c->point;

			pointlist->Add(*c->point);

		}

		

		array<Point>^ pointarray =  pointlist->ToArray();


		Pen^ myPen = gcnew Pen(Color::Blue, 2);
				GraphicsPath^ path = gcnew GraphicsPath;

		Single tension = 0.4F;

		path->AddCurve(pointarray, tension);

		gap->DrawPath(myPen, path);


	
	}

	void JillesSpline::CreateChartControlCircles(List<Circle^>^ circles)
	{

		int nc = circles->Count;

		//List<Circle^>^ bezcircles;

		for (int a = 0; a < nc - 1; a++)
		{


			int deltax2 = circles[a + 1]->point->X - circles[a]->point->X;
			int deltay2 = circles[a + 1]->point->Y - circles[a]->point->Y;

			int cax = circles[a]->point->X;
			int	cay = circles[a]->point->Y;
			int ca1y = circles[a + 1]->point->Y;

			

			int cb1x = (1.0/3) * deltax2;  // works dividing integers gives integer rounded down 1/3 = 0

			Circle^ circle2 = gcnew Circle(gcnew Point((circles[a]->point->X + Convert::ToInt32((1.0 / 3)*deltax2)), circles[a]->point->Y), 3);

			
			Circle^ circle3 = gcnew Circle(gcnew Point((circles[a]->point->X + Convert::ToInt32((2.0 / 3)*deltax2)), circles[a + 1]->point->Y), 3);
			
			bezcircles->Add(circle2);
			bezcircles->Add(circle3);
			
		}
	}

	void JillesSpline::DrawSpline( List<Circle^>^ circles)
	{

		//Pen^ myPen = gcnew Pen(Color::Blue, 2);
		
	
		GraphicsPath^ path = gcnew GraphicsPath;

		Point^ start = gcnew Point(circles[0]->point->X, circles[0]->point->Y);                                    // for fill in first and last point and their tranlsation to the xaxis
		Point^ end = gcnew Point(circles[(circles->Count) - 1]->point->X, circles[(circles->Count) - 1]->point->Y);
		Point^ start0 = gcnew Point(circles[0]->point->X, xaxis0);
		Point^ end0 = gcnew Point(circles[(circles->Count) - 1]->point->X, xaxis0);

		DrawCircle(start, Color::Yellow);
		DrawCircle(start0, Color::Yellow);
		DrawCircle(end, Color::Yellow);
		DrawCircle(end0, Color::Yellow);


		for (int i = 0; i <= (circles->Count) - 2; i++)
		{
			Circle^ bezcircle = circles[i];
			Circle^ nextbezcircle = circles[i+1];

			Circle^ nextcontrolcircle = bezcircles[2*i];
			Circle^ secondcontrolcircle = bezcircles[2*i + 1];



			path->AddBezier(bezcircle->point->X, bezcircle->point->Y, nextcontrolcircle->point->X, nextcontrolcircle->point->Y,
				secondcontrolcircle->point->X, secondcontrolcircle->point->Y, nextbezcircle->point->X, nextbezcircle->point->Y);
		
			

		}
	
		

		
		path->AddLine(*end, *end0);
		path->AddLine(*end0, *start0);
		path->AddLine(*start0, *start);
			
		

		gap->DrawPath(gcnew Pen(Color::Green, 2), path);
		
		
		gap->FillPath(gcnew SolidBrush(Color::BlueViolet), path);
	}

	void JillesSpline::DrawChartCircles( List<Circle^>^ circles)
	{
		Pen^ redPen = gcnew Pen(Color::Red, 1);
	
		
		for each(Circle^ circle in circles)
		{

			gap->DrawArc(redPen, circle->point->X, circle->point->Y, circle->r * 2, circle->r * 2, 0, 360);

		}



	}

	void JillesSpline::DrawCircle( Point^ po, Color co)
	{
		int r = 3;
		Pen^ redPen = gcnew Pen(co, 5);
	

		

			gap->DrawArc(redPen, po->X-5, po->Y, r * 2, r * 2, 0, 360);



	}


	void JillesSpline::DrawXaxisMarksAndLegenda( List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles)
	{
		const int count = circles->Count - 1;
		int length = 10;
		std::vector<VerticalLineLegendaAxis> verticallines;

		Pen^ redPen = gcnew Pen(Color::Red, 1);
			Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);

		for (int i = 0; i < circles->Count; i++)
		{
			VerticalLineLegendaAxis *verticalline = new VerticalLineLegendaAxis(); //Demo *p_demo = new Demo();http://www.cplusplus.com/forum/general/37962/
			verticalline->x = circles[i]->point->X;
			verticalline->length = length;
			verticallines.push_back(*verticalline);

			gap->DrawLine(redPen, verticallines[i].x, xaxis0, verticallines[i].x, xaxis0 + length);


			String^ drawString = pairs[i].Key;	

			SizeF stringSize  = gap->MeasureString(drawString, drawFont);
			int halfStringsizeWidth = stringSize.Width / 2;

		
			PointF^ drawPoint = gcnew PointF(verticallines[i].x- halfStringsizeWidth, xaxis0 + length);
			gap->DrawString(drawString, drawFont, drawBrush, *drawPoint);

		}
	}

	void JillesSpline::DrawYaxisMarksAndLegenda( List<KeyValuePair<String^, double>>^ pairs, List<Circle^>^ circles)
	{
		
		int count = circles->Count - 1;
		int numberofhorizontallines = 10;
		int length = 10;
		std::vector<HorizontalLineLegendaAxis> horizontallines;
		double ylegenda;

		Pen^ redPen = gcnew Pen(Color::Red, 1);
	
		Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);



		for (int i = 0; i <= numberofhorizontallines - 1; i++)
		{
			HorizontalLineLegendaAxis *horizontalline = new HorizontalLineLegendaAxis;
			horizontalline->y = xaxis0 - yaxislength / numberofhorizontallines * (i + 1);		
			horizontalline->length = length;
			horizontallines.push_back(*horizontalline);
			gap->DrawLine(redPen, yaxis0, horizontallines[i].y, yaxis0 - length, horizontallines[i].y);

			ylegenda = Math::Round((1.0 / numberofhorizontallines) * pairsymax / 2, 2);

			ylegenda = ylegenda * (i + 1);
			String^ drawString = System::Convert::ToString(ylegenda);
			String^ drawString2 = System::Convert::ToString(i);
			PointF^ drawPoint = gcnew PointF(yaxis0 - 30, horizontallines[i].y - 20);
			PointF^ drawPoint2 = gcnew PointF(yaxis0 - 30, horizontallines[i].y);

			gap->DrawString(drawString, drawFont, drawBrush, *drawPoint);
			gap->DrawString(drawString2, drawFont, drawBrush, *drawPoint2);

		
		}

	
	}

} //namespace




