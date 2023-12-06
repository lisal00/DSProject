#include <wx/wx.h>
#include "infix.h"
#include "binary.h"
#include "calculator.h"
#include "string"
#include <iostream>

class MainFrame : public wxFrame
{
private:
	wxButton *calB;
	wxButton *binB;
	wxButton *postfixB;
	wxButton *resetB;

	wxStaticText *directions = nullptr;
	wxTextCtrl *textBox = nullptr;
	calculator calcClass;
	infix infix;
	wxTextCtrl *resTextBox = nullptr;
	wxButton *calculateButton = nullptr;

public:
	MainFrame(const wxString &title);

	void OnCalculatorSelection(wxCommandEvent &event);
	void OnBinarySelection(wxCommandEvent &event);
	void OnPostfixSelection(wxCommandEvent &event);

	// Event handlers for buttons
	void handlePostfix(wxCommandEvent &event);
	void handleCalculate(wxCommandEvent &event);
	void handleBinary(wxCommandEvent &event);

	void resetState();
};
