#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "jnunes.com - minefield")
{
  btn = new wxControl*[nFieldWidth * nFieldHeight];
  wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 1, 1);

  nField = new int[nFieldWidth * nFieldHeight];

  for (int x = 0; x < nFieldWidth; x++)
  {
    for (int y = 0; y < nFieldHeight; y++)
    {
      int currenItem = y * nFieldWidth + x;
      btn[currenItem] = new wxControl(this, 10000 + currenItem);
      btn[currenItem]->SetWindowVariant(wxWINDOW_VARIANT_NORMAL);
      btn[currenItem]->SetBackgroundColour(wxColour(127, 127, 127));
      btn[currenItem]->SetMinSize(wxSize(20, 20));;
      btn[currenItem]->Bind(wxEVT_LEFT_DOWN, &cMain::OnButtonClicked, this);

      nField[currenItem] = 0;

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

void cMain::OnButtonClicked(wxMouseEvent &evt) {
  int x = (evt.GetId() - 10000) % nFieldWidth;
  int y = (evt.GetId() - 10000) / nFieldWidth;

  if (bFirstClick)
  {
    int mines =  30;

    while (mines)
    {
      int rx = rand() % nFieldWidth;
      int ry = rand() % nFieldHeight;
      int currentItem = ry * nFieldWidth + rx;

      if (nField[currentItem] == 0 && rx != x && ry != y)
      {
        nField[currentItem] = -1;
        mines--;
      }
    }
    bFirstClick = false;
  }

  int currentPosition = y * nFieldWidth + x;

  btn[currentPosition]->SetBackgroundColour(wxColour(0, 0, 0));
  btn[currentPosition]->Refresh();
  btn[currentPosition]->Enable(false);

  // Check if player clicked on mine
  if (nField[currentPosition] == -1)
  {
    wxMessageBox("BOOOMMM! - Game Over :(");

    // Reset the game
    for (int x = 0; x < nFieldWidth; x++)
    {
      for (int y = 0; y < nFieldHeight; y++)
      {
        int currentPositionForReset = y * nFieldWidth + x;
        nField[currentPositionForReset] = 0;
        btn[currentPositionForReset]->SetBackgroundColour(wxColour(127, 127, 127));
        btn[currentPositionForReset]->Enable(true);
        btn[currentPositionForReset]->Refresh();
      }
    }
  }

  evt.Skip();
}


