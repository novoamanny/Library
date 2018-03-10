#include "controller.h"
#include "view.h"
#include "library.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::click() {
  int cmd = -1;
  while (cmd != 0) {
    view.show_menu();
    cout << "Command? ";
    cin >> cmd;
    cin.ignore(65535, '\n'); // consume \n
    //execute_cmd(cmd);
  }
}