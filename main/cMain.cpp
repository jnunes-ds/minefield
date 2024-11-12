#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
  EVT_BUTTON(10001, cMain::OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "jnunes.com - minefield")
{

  btn = new wxControl*[nFieldWidth * nFieldHeight];
  wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 1, 1);

  for (int x = 0; x < nFieldWidth; x++)
  {
    for (int y = 0; y < nFieldHeight; y++)
    {
      int currentButton = y * nFieldWidth + x;
      btn[currentButton] = new wxControl(this, 10000 + currentButton);
      btn[currentButton]->SetWindowVariant(wxWINDOW_VARIANT_NORMAL);
      btn[currentButton]->SetBackgroundColour(wxColour(127, 127, 127));
      btn[currentButton]->SetMinSize(wxSize(20, 20));;

      grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL, 0);
    }
  }

  this->SetSizerAndFit(grid);
  grid->Layout();
}

cMain::~cMain()
{
  delete[]btn;
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
}


