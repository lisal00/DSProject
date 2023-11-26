#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString &title)
		: wxFrame(NULL, wxID_ANY, title)
	{

		// Create a button
		wxButton *calB = new wxButton(this, wxID_ANY, "Calculate", wxPoint(200, 50), wxSize(200, 60), 0);
		wxButton *binB = new wxButton(this, wxID_ANY, "Binary Converter", wxPoint(450, 50), wxSize(200, 60), 0);
		wxButton *postfixB = new wxButton(this, wxID_ANY, "Postfix Converter", wxPoint(700, 50), wxSize(200, 60), 0);
		wxStaticText *staticText = new wxStaticText(this, wxID_ANY, "Enter an ex");

		// Bind a function to handle button click events
		calB->Bind(wxEVT_BUTTON, &MyFrame::OnCalBClick, this);
		// binB->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
		this

			// Event handler for button click
			void
			OnCalBClick(wxCommandEvent & event)
		{

			// Show an input box
		}

		// Declare the event table
		wxDECLARE_EVENT_TABLE();
	};

	// Event table for MyFrame
	wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
		EVT_BUTTON(wxID_ANY, MyFrame::OnCalBClick)

			wxEND_EVENT_TABLE()

				class MyApp : public wxApp
	{
	public:
		virtual bool OnInit()
		{
			MyFrame *frame = new MyFrame("Our very great project DU MA 他媽的");
			frame->SetClientSize(1000, 500);
			frame->Center();
			frame->Show(true);
			return true;
		}
	};

	wxIMPLEMENT_APP(MyApp);
