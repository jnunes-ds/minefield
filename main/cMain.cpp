#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "jnunes.com - minefield")
{
  m_btn1 = new wxButton(this, wxID_ANY, "Click here!", wxPoint(10, 10), wxSize(150, 50));
  m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
  m_list = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain::~cMain()
{
}
