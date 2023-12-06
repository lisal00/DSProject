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

	wxStaticText *staticText;
	wxTextCtrl *textBox;
	calculator calcClass;
	infix infix;
	wxTextCtrl *control;
	wxTextCtrl *resTextBox;
	wxButton *calculateButton;

public:
	MainFrame(const wxString &title);

	// Event handlers for buttons
	void OnCalculatorSelection(wxCommandEvent &event);
	void OnBinarySelection(wxCommandEvent &event);
	void OnPostfixSelection(wxCommandEvent &event);

	void handlePostfix(wxCommandEvent &event);
	void handleCalculate(wxCommandEvent &event);
	void handleBinary(wxCommandEvent &event);

	void resetState(wxCommandEvent &event);
};
