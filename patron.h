#ifndef __PATRON_H
#define __PATRON_H

#include <string>
#include <iostream>

using namespace std;

class Patron{
    public:
    Patron(string _name, string _phone) : name(_name), phone(_phone) { }
    string to_string();

    //class Invalid_transaction { };

    private:
    string name;
    string phone;
};
#endif