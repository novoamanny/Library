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
(9) Help
(0) Exit
)";

    cout << menu << endl;
}