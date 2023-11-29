#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{

	// Create a button
	calB = new wxButton(this, wxID_ANY, "Calculate", wxPoint(200, 50), wxSize(200, 60), 0);
	binB = new wxButton(this, wxID_ANY, "Binary Converter", wxPoint(450, 50), wxSize(200, 60), 0);
	postfixB = new wxButton(this, wxID_ANY, "Postfix Converter", wxPoint(700, 50), wxSize(200, 60), 0);

	// Bind event handlers to buttons
	calB->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Click, this);
	binB->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Click, this);
	postfixB->Bind(wxEVT_BUTTON, &MainFrame::OnButton3Click, this);
}

void MainFrame::OnButton1Click(wxCommandEvent& event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	wxButton* calculateB = new wxButton(this, wxID_ANY, "=", wxPoint(575, 250), wxSize(100, 20), 0);
	calculateB->Bind(wxEVT_BUTTON, &MainFrame::handleCalculate, this);
}

void MainFrame::OnButton2Click(wxCommandEvent& event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(150, 250));
	wxTextCtrl* control = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(300, 250));
	wxStreamToTextRedirector redirect(control);
}

void MainFrame::OnButton3Click(wxCommandEvent& event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(150, 250));
	wxTextCtrl* control = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(300, 250));
	wxStreamToTextRedirector redirect(control);
}

void MainFrame::handleCalculate(wxCommandEvent& event)
{
	wxString expression = textBox->GetValue();
	string expressionStr = string(expression.mb_str());
	string postfix = infix.convert(expressionStr);
	staticText = new wxStaticText(this, wxID_ANY, postfix, wxPoint(150, 400));

	int res = calcClass.eval(postfix);
}
