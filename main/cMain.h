#pragma once
#include <wx/wx.h>



class cMain : public wxFrame
{
public:
  cMain();
  ~cMain();

public:
  int nFieldWidth = 10;
  int nFieldHeight = 10;
  wxControl **btn;
  int *nField = nullptr;
  bool bFirstClick = true;
  std::vector<wxStaticText*> labels;

  void OnButtonClicked(wxMouseEvent &evt);

  wxDECLARE_EVENT_TABLE();
};


