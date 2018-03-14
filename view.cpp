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