// SplineFormCpp1.cpp : main project file.
// empty form project with 1 form 
//http://social.msdn.microsoft.com/Forums/en-US/a6d92d96-4a86-4ef7-a815-7f588a6073ea/vs-express-2012-no-c-windows-forms-application?forum=Vsexpressvc

//#include "ClassesAndStructures.h"
#include "stdafx.h"
#include "MyForm.h"
#include "JillesSpline.h"

using namespace System;
using namespace System::Windows::Forms;



int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SplineFormCpp2::MyForm form;
	Application::Run(%form);






}
