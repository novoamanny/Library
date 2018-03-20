#include "patron.h"

#include <iostream>
#include <string>

using namespace std;

string Patron::to_string(){
    string pat = name + ", " + phone + "\n";
    return pat;
}