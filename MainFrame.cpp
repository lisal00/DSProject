#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{

	// Create a button
	calB = new wxButton(this, wxID_ANY, "Calculator", wxPoint(200, 50), wxSize(200, 60), 0);
	binB = new wxButton(this, wxID_ANY, "Binary Converter", wxPoint(450, 50), wxSize(200, 60), 0);
	postfixB = new wxButton(this, wxID_ANY, "Postfix Converter", wxPoint(700, 50), wxSize(200, 60), 0);
	resetB = new wxButton(this, wxID_ANY, "Reset", wxPoint(50, 50), wxSize(100, 20), 0);

	// Bind event handlers to buttons
	calB->Bind(wxEVT_BUTTON, &MainFrame::OnCalculatorSelection, this);
	binB->Bind(wxEVT_BUTTON, &MainFrame::OnBinarySelection, this);
	postfixB->Bind(wxEVT_BUTTON, &MainFrame::OnPostfixSelection, this);
	resetB->Bind(wxEVT_BUTTON, &MainFrame::resetState, this);
}

void MainFrame::OnCalculatorSelection(wxCommandEvent &event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "=", wxPoint(575, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handleCalculate, this);
}

void MainFrame::OnBinarySelection(wxCommandEvent &event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter a positive integer: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(395, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "Convert", wxPoint(595, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handleBinary, this);
}

void MainFrame::OnPostfixSelection(wxCommandEvent &event)
{
	staticText = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "Convert", wxPoint(585, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handlePostfix, this);
}

void MainFrame::handlePostfix(wxCommandEvent &event)
{
	wxString numberWx = textBox->GetValue();
	string numberStr = numberWx.ToStdString();
	string postfix = infix.convert(numberStr);

	resTextBox = new wxTextCtrl(this, wxID_ANY, postfix, wxPoint(700, 250), wxSize(500, 20), wxTE_READONLY);
}

void MainFrame::handleBinary(wxCommandEvent &event)
{
	wxString numberWx = textBox->GetValue();
	string numberStr = numberWx.ToStdString();
	int number = stoi(numberStr);
	string resultStr = DectoBin(number);

	resTextBox = new wxTextCtrl(this, wxID_ANY, resultStr, wxPoint(700, 250), wxSize(500, 20), wxTE_READONLY);
}

void MainFrame::handleCalculate(wxCommandEvent &event)
{
	wxString expression = textBox->GetValue();
	string expressionStr = expression.ToStdString();
	string postfix = infix.convert(expressionStr);

	int result = calcClass.eval(postfix);
	string resultStr = to_string(result);
	// staticText = new wxStaticText(this, wxID_ANY, resultStr, wxPoint(700, 250));
	resTextBox = new wxTextCtrl(this, wxID_ANY, resultStr, wxPoint(680, 250), wxSize(500, 20), wxTE_READONLY);
}

void MainFrame::resetState(wxCommandEvent &event)
{
	staticText->Destroy();
	textBox->Destroy();
	calculateButton->Destroy();

	if (resTextBox)
		resTextBox->Destroy();
}