#include "Frame.h"
#include <wx/wx.h>


class MyApp : public wxApp {

public:
	virtual bool OnInit();
	virtual int OnExit() { return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	Frame * Okno = new Frame(NULL);
	Okno->Show();
	return 1;
}
