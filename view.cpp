#include "view.h"
#include <iostream>
#include <string>

using namespace std;

void View::show_menu() {
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

Utility
-------
(8) Test System
(9) Help
(0) Exit
)";

    cout << menu << endl;
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
(9) Help - Print this text.
(0) Exit - Exit the program. WARNING: The current version does NOT
    save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
  )";
  cout << helptext << endl;
}