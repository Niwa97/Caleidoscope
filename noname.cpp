///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,300 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	bSizer2->SetMinSize( wxSize( 300,300 ) ); 
	Panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 300,300 ), wxTAB_TRAVERSAL );
	Panel->SetMinSize( wxSize( 300,300 ) );
	
	bSizer2->Add( Panel, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	Wczytaj_Button = new wxButton( this, wxID_ANY, wxT("Wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( Wczytaj_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Zapisz_Button = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( Zapisz_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Reset_Button = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( Reset_Button, 0, wxALL, 5 );
	
	Slider = new wxSlider( this, wxID_ANY, 2, 2, 20, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( Slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Tekst = new wxStaticText( this, wxID_ANY, wxT("Osie"), wxDefaultPosition, wxDefaultSize, 0 );
	Tekst->Wrap( -1 );
	bSizer3->Add( Tekst, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Slider2 = new wxSlider( this, wxID_ANY, 0, 0, 26, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( Slider2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Kat = new wxStaticText( this, wxID_ANY, wxT("WKat"), wxDefaultPosition, wxDefaultSize, 0 );
	Kat->Wrap( -1 );
	bSizer3->Add( Kat, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer1->Add( bSizer3, 0, 0, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Panel->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Connect( wxEVT_SIZE, wxSizeEventHandler( MyFrame::Zmiana_Rozmiaru ), NULL, this );
	Panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::Repaint ), NULL, this );
	Wczytaj_Button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Wczytaj ), NULL, this );
	Zapisz_Button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Zapisz ), NULL, this );
	Reset_Button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Reset ), NULL, this );
	Slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Osie ), NULL, this );
	Slider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Zmiana_Kata ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	Panel->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( MyFrame::Kontrola ), NULL, this );
	Panel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MyFrame::Zmiana_Rozmiaru ), NULL, this );
	Panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::Repaint ), NULL, this );
	Wczytaj_Button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Wczytaj ), NULL, this );
	Zapisz_Button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Zapisz ), NULL, this );
	Reset_Button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Reset ), NULL, this );
	Slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Osie ), NULL, this );
	Slider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Zmiana_Kata ), NULL, this );
	
}
