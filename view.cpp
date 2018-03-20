#include "view.h"
#include "genre.h"
#include "age.h"
#include "media.h"
#include "dialogs.h"
#include <iostream>
#include <string>

using namespace std;

int View::select_from_menu() {
    string menu = R"(
=================================
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication
(5) Add A Patron
(6) List all patrons

Utility
-------
(8) Test System
(9) Help
(0) Exit
)";

    //cout << menu << endl;

    string result = Dialogs::input(menu, "Main Menu");
    try {
        return (result == "CANCEL") ? 0 : stoi(result);
    } catch (...){
        return -1;
    }
}

void View::list_publications(){
    string header = R"(
=============================================
L I S T  O F  A L L  P U B L I C A T I O N S
=============================================
    )";

    cout << header;
    /*
    int i;

    for (i = 0; i < library.number_of_publications(); i++){
        cout << "\n" << i << ")" << library.publication_to_string(i);
    }

        // Need to modify code for exception
    */
 if (library.number_of_publications() <= 0){
     throw Invalid_transaction();
 }
 else {
    int i;

    for (i = 0; i < library.number_of_publications(); i++){
        cout << "\n" << i << ")" << library.publication_to_string(i);
    }
 }
 
}

void View::list_patrons(){
    string header = R"(
=============================================
     L I S T  O F  A L L  P A T R O N S
=============================================
    )";

    cout << header;
    /*
    int i;

    for (i = 0; i < library.number_of_publications(); i++){
        cout << "\n" << i << ")" << library.publication_to_string(i);
    }

        // Need to modify code for exception
    */
 //if (library.number_of_patrons() <= 0){
   //  throw Invalid_transaction();
 //}
// else {
    int i;

    for (i = 0; i < library.number_of_patrons(); i++){
        cout << "\n" << i << ")" << library.patrons_to_string(i);
   }
 //}
}

void View::help(){

    string header = R"(
----------------------------
      H E L P  M E N U
----------------------------
)";
  cout << header;
  
    string helptext = R"(
The LMS tracks publication assets for a library, including those who
check out and return those publications.

(1) Add publication - This allows the librarian to enter data 
    associated with a new publication. 
(2) List all publications - All data known about each publication
    in the library is listed.
(3) Check out publication - Enter the data for patrons who check out
    a publication, and mark that publication as checked out.
(4) Check in publication - Select a publication and mark it as checked in.
(5) Add patron - This allows the librarian to enter data associated with a new patron.
(6) List all patrons - All data known about each patron in the library is listed.
(9) Help - Print this text.
(0) Exit - Exit the program. WARNING: The current version does NOT
    save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
  )";
  cout << helptext << endl;
}