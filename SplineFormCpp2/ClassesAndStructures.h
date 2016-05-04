#pragma once

using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections;
namespace SplineFormCpp2 {

	public ref class ClassesAndStructures
	{
	public:
		ClassesAndStructures();

		String^  createrandombuienradarstring();
		String^ leftPad(int number, int targetLength);
		List<KeyValuePair<String^, Double>>^ result(String^ a);
		void result22(String^ a);








	};


	


	struct VerticalLine
	{
		int x;
	};

	struct HorizontalLine
	{
		int y;
	};

	struct VerticalLineLegendaAxis
	{
		int x;
		int length;

	};


	struct HorizontalLineLegendaAxis
	{
		int y;
		int length;


	};

	ref class Pair
	{
		Pair(String^ s, Double r);
		property String^  time;
		property Double rain;
	};

	//ref class GenericList
	//{
	//public:

	//	property List<KeyValuePair<String^, Double>> genlist;
	//	
	//};

}