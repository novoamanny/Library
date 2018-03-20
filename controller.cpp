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

    // A D D  A  P U B L I C A T I O N
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

    // L I S T  A L L  P U B L I C A T I O N S
      else if (cmd == 2){
         // view.list_publications();

         try{
             view.list_publications();
         } catch (View::Invalid_transaction e){
             cerr << "\nERROR: No Current Publications to Display!" << endl;
         }
      }

    // C H E C K  O U T
      else if (cmd == 3){
          view.list_publications();
          

          int index;
          string pat_name, pat_phone;

          cout << endl << "Enter Publication Index Number: ";
          cin >> index;
          cin.ignore(65535, '\n'); // consume \n
            
            // Check if the index number is out of range
          if (0 > index || index >= library.number_of_publications()){
              return;
          }

            cout << "Patron name? ";
            getline(cin, pat_name);
            if (pat_name.size() == 0) return;

            cout << "Patron phone? ";
            getline(cin, pat_phone);
            if (pat_phone.size() == 0) return;

            try {
            library.check_out(index, pat_name, pat_phone);
            } catch(Publication::Invalid_transaction e) {
             cerr << "ERROR: That publication is already checked out!" << endl;
            } 
        }

    // C H E C K  I N
      else if (cmd == 4){
            view.list_publications();

            int index;

            cout << endl << "Enter Publication Index Number: ";
            cin >> index;
            cin.ignore(65535, '\n'); // consume \n
            
            // Check if the index number is out of range
          if (0 > index || index >= library.number_of_publications()){
              return;
          }

            try {
                library.check_in(index);
            } catch(Publication::Invalid_transaction e) {
                cerr << "ERROR: That publication is already checked in!" << endl;
            }
        }

    // T E S T
      else if (cmd == 8){
            library.test();
       }
    
    // H E L P
       else if (cmd == 9){
           view.help();
       }
    // E X I T
       else if (cmd == 0){
           // E X I T
       }

       else{
           cerr << "**** Invalid command - type 9 for help" << endl << endl;
       }
  }