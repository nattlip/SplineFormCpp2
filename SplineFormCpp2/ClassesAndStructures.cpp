#include "stdafx.h"
#include "JillesSpline.h"
#include "MyForm.h"
#include <string>


namespace SplineFormCpp2 {

	ClassesAndStructures::ClassesAndStructures()
	{

	};

	String^ ClassesAndStructures::createrandombuienradarstring(){

		String^ returnstring = gcnew String("");
		int nc = 25;

		System::DateTime^ oldDateObj = System::DateTime::Now;

		Random^ randObj = gcnew Random;

		for (int i = 0; i <= nc; i++){

			DateTime^ newDateObj = oldDateObj->AddMinutes(i * 5);

			int u = newDateObj->Hour;
			int m = newDateObj->Minute;

			int mroundingon5 = 5 * rint(m / 5);

			//mroundingon5 = mroundingon5 % 60;

			int y;

			y = randObj->Next(100);

			String^ ytostring = leftPad(y, 3);

			returnstring = returnstring + ytostring + "|" + u.ToString() + ":" + leftPad(mroundingon5, 2) + " "+ "\r\n";

		}







		return returnstring;

	};


	// 
	void ClassesAndStructures::result22(String^ a)
	{
		array<Char>^ sep = gcnew array<Char>{' '};

		array<String^>^  raintimepairs = a->Split(sep, StringSplitOptions::None);

		//KeyValuePair<String^, Double>^ raintimepair;

		List<KeyValuePair<String^, Double>>^ raintimepairlist = gcnew List<KeyValuePair<String^, Double>>();

		array<KeyValuePair<String^, Double>>^ raintimemepairarray = gcnew array<KeyValuePair<String^, Double>, 1>(0);  // not used




		for (int i = 0; i < raintimepairs->Length - 2; i++){

			String^ d = raintimepairs[i];
			String^ e = raintimepairs[i]->Split('|')[1];
			String^ f = raintimepairs[i]->Split('|')[0];
			array<System::String^, 1>^ h = raintimepairs[i]->Split('|');


			String^ t = h[1];
			String^ r = h[0];

			int q = Convert::ToInt32(r);
			double w = q - 109;
			double y = w / 32;
			double u = Math::Pow(10, y);


			double k = ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32));
			double l = Math::Pow(10, (((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32));


			Double  b = Math::Round((Math::Pow(10, ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32))), 2));
			double m = Math::Round(u, 2);

			KeyValuePair<String^, Double>^ raintimepair = gcnew KeyValuePair<String^, Double>(t, m);



			/*KeyValuePair<String^, Double>^ raintimepair = gcnew KeyValuePair<String^, Double>(raintimepairs[i]->Split('|')[1],
			Math::Round((10 ^ ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32)), 2)));*/


			raintimepairlist->Add(*raintimepair);






		};


	}



	List<KeyValuePair<String^, Double>>^ ClassesAndStructures::result(String^ a)
	{
		int b = 77;
		//Dim c As Object = 10 ^ ((b - 109) / 32)


		array<Char>^ sep = gcnew array<Char>{'\n'};

		array<String^>^  raintimepairs = a->Split(sep, StringSplitOptions::None);

		//KeyValuePair<String^, Double>^ raintimepair;

		List<KeyValuePair<String^, Double>>^ raintimepairlist = gcnew List<KeyValuePair<String^, Double>>();

		array<KeyValuePair<String^, Double>>^ raintimemepairarray = gcnew array<KeyValuePair<String^, Double>, 1>(0);  // not used


		for (int i = 0; i < raintimepairs->Length - 2; i++){

			String^ d = raintimepairs[i];
			String^ e = raintimepairs[i]->Split('|')[1];
			String^ f = raintimepairs[i]->Split('|')[0];
			array<System::String^, 1>^ h = raintimepairs[i]->Split('|');


			String^ t = h[1];
			String^ r = h[0];

			int q = Convert::ToInt32(r);
			double w = q - 109;
			double y = w / 32;
			double u = Math::Pow(10, y);


			double k = ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32));
			double l = Math::Pow(10, (((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32));


			Double  b = Math::Round((Math::Pow(10, ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32))), 2));
			double m = Math::Round(u, 2);

			KeyValuePair<String^, Double>^ raintimepair = gcnew KeyValuePair<String^, Double>(t, m);



			/*KeyValuePair<String^, Double>^ raintimepair = gcnew KeyValuePair<String^, Double>(raintimepairs[i]->Split('|')[1],
				Math::Round((10 ^ ((((Convert::ToInt32((raintimepairs[i]->Split('|')[0]))) - 109) / 32)), 2)));*/


			raintimepairlist->Add(*raintimepair);






		};

		return raintimepairlist;

	};

	Pair::Pair(String^ s, Double r)
	{
		time = s;
		rain = r;

	}


	//Public Shared Function result(ByVal a As String) As List(Of KeyValuePair(Of String, Double))
	//
	//Dim b As Integer = 77
	//
	//Dim c As Object = 10 ^ ((b - 109) / 32)
	//
	//Dim arg() As String = { " " }
	//
	//Dim raintimepairs As String() = a.Split(arg, StringSplitOptions.None)
	//
	//Dim datum As Date = Now.ToShortTimeString
	//
	//Dim raintimepair As KeyValuePair(Of String, Double)
	//
	//Dim raintimepairlist As New List(Of KeyValuePair(Of String, Double))
	//
	//
	//Dim raintimemepairarray As Array
	//raintimemepairarray = {}
	//
	//
	//
	//
	//
	//
	//For i As Integer = 0 To raintimepairs.Length - 2
	//
	//
	//raintimepair = New KeyValuePair(Of String, Double)(raintimepairs(i).Split("|")(1), _
	//Math.Round((10 ^ ((((CInt(raintimepairs(i).Split('|')(0)))) - 109) / 32)), 2))
	//
	//
	//raintimepairlist.Add(raintimepair)
	//
	//
	//
	//
	//
	//
	//Next
	//
	//
	//Return raintimepairlist
	//
	//
	//
	//
	//End Function












	String^ ClassesAndStructures::leftPad(int number, int targetLength){

		String^ output = number.ToString();

		while (output->Length < targetLength) {

			output = "0" + output;


		};


		return output;
	};


}




	