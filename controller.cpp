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
    execute_cmd(cmd);
  }
} 

void Controller::execute_cmd(int cmd){
      if (cmd == 1){
          string title, author, isbn, copyright;

        
          cout << "Title?" << endl;
          cout << "-> ";
          getline(cin, title);
          cout << endl;

          if (title.size() == 0){
              return;
          }

          cout << "Author?" << endl;
          cout << "-> ";
          getline(cin, author);
          cout << endl;

          if (author.size() == 0){
              return;
          }

          cout << "isbn?" << endl;
          cout << "-> ";
          getline(cin, isbn);
          cout << endl;

          if (isbn.size() == 0){
              return;
          }

          cout << "Copyright?" << endl;
          cout << "-> ";
          getline(cin, copyright);
          cout << endl;

          if (copyright.size() == 0){
              return;
          }

          library.add_publication(Publication(title, author, copyright, isbn));
      }
  }