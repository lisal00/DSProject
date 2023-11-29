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
	wxStaticText *staticText;
	wxTextCtrl *textBox;
	calculator calcClass;
	infix infix;

public:
	MainFrame(const wxString& title);

	// Event handlers for buttons
	void OnButton1Click(wxCommandEvent& event);
	void OnButton2Click(wxCommandEvent& event);
	void OnButton3Click(wxCommandEvent& event);

	void handleCalculate(wxCommandEvent& event);
};
