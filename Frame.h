#pragma once
//Tutaj jest deklaracja klasy Frame, glownego okno
//Komplementarny plik cpp zawiera definicje metod tej klasy
//W tym pliku i podobnym cpp bedziemy pracowac

#include "noname.h"
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
#include <wx/log.h>

class Frame : public MyFrame
{
public:
	Frame(wxWindow * parent);
	virtual void Wczytaj(wxCommandEvent& event);
	virtual void Zapisz(wxCommandEvent& event);
	virtual void Repaint();
	virtual void WxPanel_Repaint(wxUpdateUIEvent& event);
	virtual void Osie(wxScrollEvent & event);
	virtual void Reset(wxCommandEvent& event);
	virtual void Zmiana_Rozmiaru(wxSizeEvent & event);
	virtual void Kalejdoskopuj(void);
	virtual void Wypelnij();
	virtual void Interpoluj(int i, int j, int x, int y);
	virtual void Zmiana_Kata(wxScrollEvent& event);
	virtual void Zapisz1(wxCommandEvent& event);
	virtual void Wkat_Tekst(wxScrollEvent& event);
	virtual void Osie_Tekst(wxScrollEvent& event);
	virtual void Wkat_Tekst(void);
	virtual void Osie_Tekst(void);

	~Frame();

private:
	wxBitmap Bitmapa;
	wxImage Wycinek;
	wxImage Kopia;
	int size;
	wxFileDialog* File_Dialog;
	wxImage Wczytany_Obrazek;
	wxImage Przeskalowany_Obrazek;
	bool Czy_Jest_Wczytany;
	bool Reset_Flaga;
	double wkat;
};