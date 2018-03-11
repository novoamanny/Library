#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "publication.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library {
    public:
        void add_publication(Publication pub);
        void test();

    private:
        vector <Publication> publications;

};
#endif