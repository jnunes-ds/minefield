#include "app/cApp.h"

wxIMPLEMENT_APP(cApp);

class Main {
public:
  Main();

  int main();
};
int Main::main() {
  cApp*  app = new cApp();
  app->OnInit();
  return 0;
}
