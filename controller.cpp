#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "dialogs.h"
#include "age.h"
#include "media.h"
#include "genre.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::click() {
  int cmd = -1;
  while (cmd != 0) {
    cmd = view.select_from_menu();
    //cout << "Command? ";
   // cin >> cmd;
   // cin.ignore(65535, '\n'); // consume \n
    execute_cmd(cmd);
  }
} 

void Controller::execute_cmd(int cmd){

    // A D D  A  P U B L I C A T I O N
      if (cmd == 1){
          string title, author, isbn, copyright;
          int age, genre, media;

        
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

          cout << "Copyright date?" << endl;
          cout << "-> ";
          getline(cin, copyright);
          cout << endl;

          if (copyright.size() == 0){
              return;
          }

          for (int i = 0; i < Genre::num_genres; ++i) 
            cout << "  " << i << ") " << Genre(i).to_string() << endl;
            cout << "Genre? ";
            cin >> genre;
            cin.ignore(65535, '\n'); // consume \n
            if (0 > genre || genre >= Genre::num_genres) return;

        for (int i = 0; i < Media::num_media; ++i) 
            cout << "  " << i << ") " << Media(i).to_string() << endl;
            cout << "Media? ";
            cin >> media;
            cin.ignore(65535, '\n'); // consume \n
            if (0 > media || media >= Media::num_media) return;

        for (int i = 0; i < Age::num_ages; ++i) 
            cout << "  " << i << ") " << Age(i).to_string() << endl;
            cout << "Age? ";
            cin >> age;
            cin.ignore(65535, '\n'); // consume \n
            if (0 > age || age >= Age::num_ages) return;

          library.add_publication(Publication(title, author, copyright, isbn, genre, media, age));
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

    else if (cmd == 5) { // Add patron
    string name, number;

    cout << "Name? ";
    getline(cin, name);
    if (name.size() == 0) return;

    cout << "Phone number? ";
    getline(cin, number);
    if (number.size() == 0) return;

    library.add_patron(Patron(name, number));
    
 } 
    else if (cmd == 6) { // List all patrons
    view.list_patrons();
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