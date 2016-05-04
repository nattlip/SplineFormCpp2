#pragma once

#include "JillesSpline.h"
#include "ClassesAndStructures.h"
#include "GraphObj.h"


namespace SplineFormCpp2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		static MyForm^ TheInstance;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pb1;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{

			TheInstance = this;
			this->pb1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pb1
			// 
			this->pb1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pb1->Location = System::Drawing::Point(34, 42);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(1200, 400);
			this->pb1->TabIndex = 0;
			this->pb1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1071, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(34, 442);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1200, 400);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1261, 860);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pb1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


				 // Create a GraphicsPath object.
				 //GraphicsPath^ myPath = gcnew GraphicsPath;

				 //// Set up and call AddArc, and close the figure.
				 //Rectangle rect = Rectangle(20, 20, 100, 100);
				 //myPath->StartFigure();
				 //myPath->AddArc(rect, 0, 180);
				 //myPath->CloseFigure();

				 //// Draw the path to screen.
				 //Graphics^  g;
				 //g = pb1->CreateGraphics();


				 //g->DrawPath(gcnew Pen(Color::Red, 3.0f), myPath);


				 //// i only need the size for reference 
				



				 System::Drawing::Size s = pb1->Size;
				 //System::Drawing::Size s = (*pb1).Size; // the same as line above
				 int padding = 20; //percentage axis are within border of control


				 Graphics^  g;

				 g = MyForm::TheInstance->pb1->CreateGraphics();


				 JillesSpline spline(g,s, padding);
				 ClassesAndStructures cs;

				 int b = spline.xaxis0;

				 int *pointer_b = &b;    // pointer of b pointer has * before or after pointer and has same type as type pointed to:  Reference operator (&)
				 int* pointer_b2 = &b;  //the punctuator % is to ^ as the punctuator & is to *. 
				 //	In C++ the unary & operator is in C++/CLI the unary % operator. While &pt yields a P*, %mngd yields at MO^.	

				 int c = *pointer_b;

			
				// cs.createrandombuienradarstring();
				// VerticalLine vl;
				 List<KeyValuePair<String^, double>>^ arr = cs.result(cs.createrandombuienradarstring());

				 spline.DrawStart(arr);

				 GraphObj go;

			     JillesSpline bitmapspline(go.g, s, padding);

				 bitmapspline.DrawStart(arr);


				 pictureBox1->Image = dynamic_cast<Image^>(go.Canvas);



	};
	};
}
