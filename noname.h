///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* Panel;
		wxButton* Wczytaj_Button;
		wxButton* Zapisz1_Button;
		wxButton* Zapisz_Button;
		wxButton* Reset_Button;
		wxSlider* Slider;
		wxStaticText* Tekst;
		wxSlider* Slider2;
		wxStaticText* Kat;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Kontrola( wxMouseEvent& event ) { event.Skip(); }
		virtual void Zmiana_Rozmiaru( wxSizeEvent& event ) { event.Skip(); }
		virtual void Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void Wczytaj( wxCommandEvent& event ) { event.Skip(); }
		virtual void Zapisz1( wxCommandEvent& event ) { event.Skip(); }
		virtual void Zapisz( wxCommandEvent& event ) { event.Skip(); }
		virtual void Reset( wxCommandEvent& event ) { event.Skip(); }
		virtual void Osie_Tekst( wxScrollEvent& event ) { event.Skip(); }
		virtual void Osie( wxScrollEvent& event ) { event.Skip(); }
		virtual void Wkat_Tekst( wxScrollEvent& event ) { event.Skip(); }
		virtual void Zmiana_Kata( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 751,534 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame();
	
};

#endif //__NONAME_H__
