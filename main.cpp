#include "MainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit()
	{
		MainFrame *frame = new MainFrame("Our very great project DU MA 他媽的");
		frame->SetClientSize(1000, 500);
		frame->Center();
		frame->Show(true);
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
