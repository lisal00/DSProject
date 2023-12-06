#include "MainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit()
	{
		/**
		Sets up window
		*/
		MainFrame *frame = new MainFrame("Calculator & Convertor");
		frame->SetClientSize(1000, 500);
		frame->Center();
		frame->Show(true);
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
