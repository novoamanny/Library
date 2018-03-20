#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "publication.h"
#include "patron.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library {
    public:
        void add_publication(Publication pub);
        void check_out(int pub_index, string pat_name, string pat_phone);
        void check_in(int pub_index);
        int number_of_publications();
        string publication_to_string(int publication_index);
        void test();
        void add_patron(Patron pat);
        int number_of_patrons();
        string patrons_to_string(int pat_index);
        
        //class Invalid_transaction { };

    private:
        vector <Publication> publications;
        vector <Patron> patrons;

};
#endif