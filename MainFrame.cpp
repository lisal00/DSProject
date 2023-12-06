#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{

	// Create a button
	calB = new wxButton(this, wxID_ANY, "Calculator", wxPoint(200, 50), wxSize(200, 60), 0);
	binB = new wxButton(this, wxID_ANY, "Binary Converter", wxPoint(450, 50), wxSize(200, 60), 0);
	postfixB = new wxButton(this, wxID_ANY, "Postfix Converter", wxPoint(700, 50), wxSize(200, 60), 0);
	// resetB = new wxButton(this, wxID_ANY, "Reset", wxPoint(50, 50), wxSize(100, 20), 0);

	// Bind event handlers to buttons
	calB->Bind(wxEVT_BUTTON, &MainFrame::OnCalculatorSelection, this);
	binB->Bind(wxEVT_BUTTON, &MainFrame::OnBinarySelection, this);
	postfixB->Bind(wxEVT_BUTTON, &MainFrame::OnPostfixSelection, this);
	// resetB->Bind(wxEVT_BUTTON, &MainFrame::resetState, this);
}

/**
 Display calculator on click
*/
void MainFrame::OnCalculatorSelection(wxCommandEvent &event)
{
	// Destroy all previous objects
	resetState();

	// Show on click
	directions = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "=", wxPoint(575, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handleCalculate, this);
}

/**
Display converter on Click
*/
void MainFrame::OnBinarySelection(wxCommandEvent &event)
{
	// Destroy all previous objects
	resetState();

	// Show on click
	directions = new wxStaticText(this, wxID_ANY, "Enter a positive integer: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(395, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "Convert", wxPoint(595, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handleBinary, this);
}

/**
Display postfix converter on click
*/
void MainFrame::OnPostfixSelection(wxCommandEvent &event)
{
	// Destroy all previous objects
	resetState();

	// Show on click
	directions = new wxStaticText(this, wxID_ANY, "Enter an expression: ", wxPoint(250, 250));
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(375, 250), wxSize(200, 20));
	wxStreamToTextRedirector redirect(textBox);
	calculateButton = new wxButton(this, wxID_ANY, "Convert", wxPoint(585, 250), wxSize(100, 20), 0);
	calculateButton->Bind(wxEVT_BUTTON, &MainFrame::handlePostfix, this);
}

/**
converts the postfix value entered by the user on click and display it to the user
*/
void MainFrame::handlePostfix(wxCommandEvent &event)
{
	wxString numberWx = textBox->GetValue(); // Get value from user
	string numberStr = numberWx.ToStdString();

	string postfix = infix.convert(numberStr); // Convert to postfix

	if (resTextBox == nullptr) // Create result text box if does not exist
		resTextBox = new wxTextCtrl(this, wxID_ANY, postfix, wxPoint(700, 250), wxSize(500, 20), wxTE_READONLY);
	else // Change value of result text box if already exist
		resTextBox->ChangeValue(postfix);
}

/**
converts the decimal value entered by the user on click and display it as a binary to the user
*/
void MainFrame::handleBinary(wxCommandEvent &event)
{
	wxString numberWx = textBox->GetValue(); // Get value from user textbox
	string numberStr = numberWx.ToStdString();
	int number = stoi(numberStr);

	string resultStr = DectoBin(number); // Convert to Binary

	if (resTextBox == nullptr) // Create result box if does not exist
		resTextBox = new wxTextCtrl(this, wxID_ANY, resultStr, wxPoint(700, 250), wxSize(500, 20), wxTE_READONLY);
	else // Change value of textbox if already exists
		resTextBox->ChangeValue(resultStr);
}

/**
calculates the expression entered in by the user on click and display the result
*/
void MainFrame::handleCalculate(wxCommandEvent &event)
{
	wxString expression = textBox->GetValue(); // Get value from textbox
	string expressionStr = expression.ToStdString();

	string postfix = infix.convert(expressionStr); // Convert to postfix before calculating

	int result = calcClass.eval(postfix); // Calculate the postfix expression
	string resultStr = to_string(result);

	// Dispay result
	if (resTextBox == nullptr)
		resTextBox = new wxTextCtrl(this, wxID_ANY, resultStr, wxPoint(680, 250), wxSize(500, 20), wxTE_READONLY);
	else
		resTextBox->ChangeValue(resultStr);
}

/**
resets the state of the program by destroying no longer relevant objects
*/
void MainFrame::resetState()
{
	if (!(directions == nullptr && textBox == nullptr && calculateButton == nullptr))
	{
		directions->Destroy();
		textBox->Destroy();
		calculateButton->Destroy();
		directions = nullptr;
		textBox = nullptr;
		calculateButton = nullptr;

		if (resTextBox != nullptr)
		{
			resTextBox->Destroy();
			resTextBox = nullptr;
		}
	}
}