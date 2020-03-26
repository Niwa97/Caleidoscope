#include "Frame.h"
#include <cmath>
#include <iostream>
#include <string>

Frame::Frame(wxWindow * parent) : MyFrame(parent) // Konstruktor
{
	Panel->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::WxPanel_Repaint), NULL, this); // Connect do rysowania

	File_Dialog = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN); // Okno dialogowe
	Wczytany_Obrazek.AddHandler(new wxJPEGHandler); // Hendler
	Przeskalowany_Obrazek.AddHandler(new wxJPEGHandler); // Hendler
	Czy_Jest_Wczytany = 0; // Flaga, mowiaca czy obrazek jest wczytany do pamieci
	Reset_Flaga = 1; // Flaga dla przycisku resetujacego
	wkat = 10 * Slider2->GetValue();
};



void Frame::Wczytaj(wxCommandEvent& event)
{
	wxString filename;
	File_Dialog->SetWildcard("JPG files (*.jpg)|*.jpg");
	if (File_Dialog->ShowModal() == wxID_OK)
	{
		filename = File_Dialog->GetPath();

		if (!Wczytany_Obrazek.LoadFile(filename, wxBITMAP_TYPE_JPEG))
			wxLogError(_("Nie mo¿na za³adowa obrazka"));
		else
		{
			wxSize P = Panel->GetSize();
			size = P.x < P.y ? P.x : P.y;
			wxImage TempImg(Wczytany_Obrazek);
			Przeskalowany_Obrazek.Create(size, size);
			Przeskalowany_Obrazek = TempImg.Scale(size, size);


			Wycinek = wxImage(size, size);
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					double r = sqrt((size / 2 - i) * (size / 2 - i) + (size / 2 - j) * (size / 2 - j));
					if (r < size / 2.0)
						Wycinek.SetRGB(i, j, Przeskalowany_Obrazek.GetRed(i, j), Przeskalowany_Obrazek.GetGreen(i, j), Przeskalowany_Obrazek.GetBlue(i, j));
					else
						Wycinek.SetRGB(i, j, 255, 255, 255);
				}
			}

			Kopia = Wycinek;
			Bitmapa = wxBitmap(Wycinek);
			Czy_Jest_Wczytany = 1;
		}	
		if (Bitmapa.Ok()) this->SetTitle(filename);
		Refresh();
	}
}


void Frame::Zapisz(wxCommandEvent& event)
{
	if (Czy_Jest_Wczytany)
	{
		double tempkat = wkat;
		wxFileDialog  saveFileDialog(this, _("Save XYZ file"), "", "", "", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		wxClientDC clientDC(this->Zapisz_Button);
		wxBufferedDC DC_Buffer(&clientDC);

		PrepareDC(DC_Buffer);

		wxInitAllImageHandlers();

		wxString fileName;

		if (saveFileDialog.ShowModal() == wxID_OK)
		{
			Repaint();
			fileName = saveFileDialog.GetPath();

			wxSize size = Zapisz_Button->GetVirtualSize();

			for (int i = 1; i < 11; i++)
			{
				Slider2->SetValue(i * 3);
				Slider->SetValue(i * 2);
				Kalejdoskopuj();
				wxString a;
				a = a.FromDouble(i);
				wxMemoryDC memory;

				wxString suma = wxString("");
				suma = fileName + a + wxString(".png");
				wkat = wkat + 10;
				memory.SelectObject(Bitmapa);
				memory.Blit(0, 0, size.GetX(), size.GetY(), &DC_Buffer, 0, 0, wxCOPY, true);

				Bitmapa.SaveFile(suma, wxBITMAP_TYPE_PNG);
			}


			wkat = tempkat;

		}
	}
}

void Frame::Zapisz1(wxCommandEvent& event)
{
	if (Czy_Jest_Wczytany)
	{
		wxFileDialog  saveFileDialog(this, _("Save XYZ file"), "", "", "(*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		wxClientDC clientDC(this->Zapisz_Button);
		wxBufferedDC DC_Buffer(&clientDC);

		PrepareDC(DC_Buffer);

		wxInitAllImageHandlers();

		wxString fileName;

		if (saveFileDialog.ShowModal() == wxID_OK)
		{
			Repaint();
			fileName = saveFileDialog.GetPath();

			wxSize size = Zapisz_Button->GetVirtualSize();


			Kalejdoskopuj();


			wxMemoryDC memory;

			memory.SelectObject(Bitmapa);
			memory.Blit(0, 0, size.GetX(), size.GetY(), &DC_Buffer, 0, 0, wxCOPY, true);

			Bitmapa.SaveFile(fileName, wxBITMAP_TYPE_PNG);

		}
	}
}

void Frame::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void Frame::Repaint()
{


	wxClientDC drawing(this->Panel);
	wxBufferedDC dc(&drawing);

	PrepareDC(dc);
	dc.SetBackground(wxBrush(wxColour(*wxWHITE)));
	dc.Clear();
	wxSize P = Panel->GetSize();
	if (Bitmapa.Ok()) dc.DrawBitmap(Bitmapa, (P.x/2) - (size/2), 0);
	
}

void Frame::Osie(wxScrollEvent& event) 
{  
	
	Tekst->SetLabel(wxString("Osie: ") + wxString::Format(wxT("%i"), Slider->GetValue()));
	Reset_Flaga = 0;

	Kalejdoskopuj();

}

void Frame::Reset(wxCommandEvent& event)
{
	if (Reset_Flaga == 0)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				double r = sqrt((size / 2 - i) * (size / 2 - i) + (size / 2 - j) * (size / 2 - j));
				if (r < size / 2.0)
					Wycinek.SetRGB(i, j, Przeskalowany_Obrazek.GetRed(i, j), Przeskalowany_Obrazek.GetGreen(i, j), Przeskalowany_Obrazek.GetBlue(i, j));
				else
					Wycinek.SetRGB(i, j, 255, 255, 255);
			}
		

		}
		
		Bitmapa = wxBitmap(Wycinek);
		
		Repaint();
		Reset_Flaga = 1;

		Slider->SetValue(2);
		Slider2->SetValue(0);

		Osie_Tekst();
		Wkat_Tekst();


	}


}

void Frame::Wypelnij()
{
	double r;
	double fi;
	double kat = 360.0/(Slider->GetValue() * 2.0);
	double fitemp;
	int l;

	int x, y;
	double www;
	double os;
	double fikompl;
	double os0, od;

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size; i++)
			{
				r = sqrt((size / 2 - i) * (size / 2 - i) + (size / 2 - j) * (size / 2 - j)); // Przejscie na wsp. bieunowe
				fi = atan2((j - size / 2), (size / 2 - i)) * (180 / M_PI) + 180; // Przejscie na wsp. biegunowe
				www = fi - wkat;
				if (www < 0)
					www = (360 - www);
				l = int (www/kat);

				
				if (r < size / 2 && fi >= kat + wkat)
				{
					if (l % 2 == 1)
						fitemp = 2 * wkat + kat - (fi - l * kat);
					else
					{
						os = (l)*kat + wkat;
						fikompl = os - (fi - os); 	//znajdujemy komplementarny punkt w wycinku
						fitemp = 2 * wkat + kat - (fikompl - (l-1) * kat);
					}
					
				
					fitemp = M_PI * (fitemp ) / 180.0;

					y = (int)(size / 2 - sin(fitemp)*r) % size;
					x = (int)(size / 2 + cos(fitemp)*r) % size;

					Interpoluj(i, j, x, y);
				
				}

				else if (r < size / 2 && fi <= wkat)
				{

					l = (int)((wkat + kat) - fi) / kat;

					if (l % 2 == 1)
					{
						fitemp = kat + (360 - l * kat - fi) - 2 * (360 - wkat);
					}
					else if (l % 2 == 0)
					{
						os = wkat + kat - kat * (l);
						fikompl = os + (os-fi);
						fitemp = kat + (360 - (l-1)* kat - fikompl) - 2 * (360 - wkat);
					}
					
					fitemp = M_PI * (fitemp) / 180.0;
					y = (int)(size / 2 - sin(fitemp)*r) % size;
					x = (int)(size / 2 + cos(fitemp)*r) % size;

					Interpoluj(i, j, x, y);
				}
			}
		}
		Kopia = Wycinek;
}


void Frame::Zmiana_Rozmiaru(wxSizeEvent & event)
{
	if (Czy_Jest_Wczytany)
	{
		int mniejsza;

		wxImage TempImg = wxImage(size, size);
		
		wxSize P = Panel->GetSize();
		mniejsza = P.x < P.y ? P.x : P.y;
		size = mniejsza;

		Przeskalowany_Obrazek = Wczytany_Obrazek.Scale(size, size);
		Bitmapa = wxBitmap(Kopia.Scale(size, size));
		
		
		Repaint();
	}
}

void Frame::Kalejdoskopuj(void)
{
	double r, fi;
	
	if (!Czy_Jest_Wczytany)
		return;

	else
	{
		Wycinek = wxImage(size, size);
		double Kat = 90 - (360 / (2 * Slider->GetValue()));
		int flagaA;
		double w1, w2;
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size; i++)
			{
				r = sqrt((size / 2 - i) * (size / 2 - i) + (size / 2 - j) * (size / 2 - j)); // Przejscie na wsp. bieunowe
				fi = atan2((j - size / 2), (size / 2 - i)) * (180.0 / M_PI) + 180.0; // Przejscie na wsp. biegunowe

				w1 = wkat;
				w2 = 360.0/ (Slider->GetValue() * 2) + wkat;
				
				if (w2 < 360)
				{
					if (fi <= w2 && fi >= w1)
						flagaA = 1;
					else flagaA = 0;
				}
				
				if (w2 >= 360)
				{
					w2 = w2 - 360.0;
					if (fi <= w2 || fi >= w1)
						flagaA = 1;
					else
						flagaA = 0;
				}
				
				

				if (r <= size / 2 &&  (flagaA ) )
				{
					Wycinek.SetRGB(i, j, Przeskalowany_Obrazek.GetRed(i, j), Przeskalowany_Obrazek.GetGreen(i, j), Przeskalowany_Obrazek.GetBlue(i, j));
				}
				else
				{
					Wycinek.SetRGB(i, j, 255, 255, 255);
				}
			}
		}

		Wypelnij();

		Bitmapa = wxBitmap(Wycinek);

	}
}
void Frame::Interpoluj(int i, int j, int x, int y)
{
	unsigned int a, b, c;

	if (x == 0 && y == 0)
	{
		a = (Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 2;
		b = (Przeskalowany_Obrazek.GetGreen(x + 1, y) + Przeskalowany_Obrazek.GetGreen(x, y + 1)) / 2;
		c =  (Przeskalowany_Obrazek.GetBlue(x + 1, y) +  Przeskalowany_Obrazek.GetBlue(x, y + 1)) / 2;
	}
	
	else if (x == size-1 && y == size-1)
	{
		a = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1)) / 2;
		b = (Przeskalowany_Obrazek.GetGreen(x - 1, y) - Przeskalowany_Obrazek.GetGreen(x, y - 1)) / 2;
		c = (Przeskalowany_Obrazek.GetBlue(x - 1, y) - Przeskalowany_Obrazek.GetBlue(x, y - 1)) / 2;
	}

	else if (x == 0)
	{
		a = (Przeskalowany_Obrazek.GetRed(x + 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		b = (Przeskalowany_Obrazek.GetRed(x + 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		c = (Przeskalowany_Obrazek.GetRed(x + 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
	}

	else if (x == size-1)
	{
		a = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		b = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		c = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
	}

	else if (y == 0)
	{
		a = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		b = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
		c = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 3;
	}

	else if (y == size-1)
	{
		a = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y - 1)) / 3;
		b = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y - 1)) / 3;
		c = (Przeskalowany_Obrazek.GetRed(x - 1, y) - Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y - 1)) / 3;
	}
	
	else
	{
		a = (Przeskalowany_Obrazek.GetRed(x - 1, y) + Przeskalowany_Obrazek.GetRed(x + 1, y) + Przeskalowany_Obrazek.GetRed(x, y - 1) + Przeskalowany_Obrazek.GetRed(x, y + 1)) / 4;
		b = (Przeskalowany_Obrazek.GetGreen(x - 1, y) + Przeskalowany_Obrazek.GetGreen(x + 1, y) + Przeskalowany_Obrazek.GetGreen(x, y - 1) + Przeskalowany_Obrazek.GetGreen(x, y + 1)) / 4;
		c = (Przeskalowany_Obrazek.GetBlue(x - 1, y) + Przeskalowany_Obrazek.GetBlue(x + 1, y) + Przeskalowany_Obrazek.GetBlue(x, y - 1) + Przeskalowany_Obrazek.GetBlue(x, y + 1)) / 4;
	}



	Wycinek.SetRGB(i, j, a, b, c);

}

Frame::~Frame()
{
	Panel->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::WxPanel_Repaint), NULL, this);
}
void Frame::Zmiana_Kata(wxScrollEvent& event)
{
	wkat = 10 * Slider2->GetValue();
	Kat->SetLabel(wxString("Kąt Obrotu: ") + wxString::Format(wxT("%i"), 10 * Slider2->GetValue()));
	Kalejdoskopuj();
}

void Frame::Wkat_Tekst(wxScrollEvent& event)
{
	Kat->SetLabel(wxString("Kąt Obrotu: ") + wxString::Format(wxT("%i"), 10*Slider2->GetValue()));
	
}

void Frame::Osie_Tekst(wxScrollEvent& event)
{
	Tekst->SetLabel(wxString("Osie: ") + wxString::Format(wxT("%i"), Slider->GetValue()));

}

void Frame::Wkat_Tekst(void)
{
	Kat->SetLabel(wxString("Kąt Obrotu: ") + wxString::Format(wxT("%i"), 10 * Slider2->GetValue()));
}

void Frame::Osie_Tekst(void)
{
	Tekst->SetLabel(wxString("Osie: ") + wxString::Format(wxT("%i"), Slider->GetValue()));
}