#pragma once
#include <wx/wx.h>



class cMain : public wxFrame
{
public:
  cMain();
  ~cMain();

public:
  wxButton* m_btn1 = nullptr;
  wxTextCtrl* m_txt1 = nullptr;
  wxListBox* m_list = nullptr;

  void OnButtonClicked(wxCommandEvent &evt);

  wxDECLARE_EVENT_TABLE();
};


