#include <wx/wx.h>
#include "infix.h"
#include "binary.h"
#include "calculator.h"
#include "string"
#include <iostream>

class MyFrame : public wxFrame
{
private:
	wxButton *calB;
	wxButton *binB;
	wxButton *postfixB;
	wxStaticText *staticText;
	wxTextCtrl *textBox;
	calculator calcClass;
	infix infix;

public:
	MyFrame(const wxString &title)
		: wxFrame(NULL, wxID_ANY, title)
	{

		// Create a button
		calB = new wxButton(this, wxID_ANY, "Calculate", wxPoint(200, 50), wxSize(200, 60), 0);
		binB = new wxButton(this, wxID_ANY, "Binary Converter", wxPoint(450, 50), wxSize(200, 60), 0);
		postfixB = new wxButton(this, wxID_ANY, "Postfix Converter", wxPoint(700, 50), wxSize(200, 60), 0);

		// Bind event handlers to buttons
		calB->Bind(wxEVT_BUTTON, &MyFrame::OnButton1Click, this);
		binB->Bind(wxEVT_BUTTON, &MyFrame::OnButton2Click, this);
		postfixB->Bind(wxEVT_BUTTON, &MyFrame::OnButton3Click, this);
	}

	// Event handlers for buttons
	void OnButton1Click(wxCommandEvent &event)
	{
		staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
		textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
		wxStreamToTextRedirector redirect(textBox);
		wxButton *calculateB = new wxButton(this, wxID_ANY, "=", wxPoint(575, 250), wxSize(100, 20), 0);
		calculateB->Bind(wxEVT_BUTTON, &MyFrame::handleCalculate, this);
	}

	void OnButton2Click(wxCommandEvent &event)
	{
		staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(150, 250));
		wxTextCtrl *control = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(300, 250));
		wxStreamToTextRedirector redirect(control);
	}

	void OnButton3Click(wxCommandEvent &event)
	{
		staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(150, 250));
		wxTextCtrl *control = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(300, 250));
		wxStreamToTextRedirector redirect(control);
	}

	void handleCalculate(wxCommandEvent &event)
	{
		wxString expression = textBox->GetValue();
		string expressionStr = string(expression.mb_str());
		string postfix = infix.convert(expressionStr);
		string res = calcClass.eval(postfix);
		cout << res;
	}
};

class MyApp : public wxApp
{
public:
	virtual bool OnInit()
	{
		MyFrame *frame = new MyFrame("Our very great project DU MA 他媽的");
		frame->SetClientSize(1000, 500);
		frame->Center();
		frame->Show(true);
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
