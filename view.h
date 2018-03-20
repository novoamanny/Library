#ifndef __VIEW_H
#define __VIEW_H

#include "library.h"

class View {
    public:
        View(Library& lib) : library(lib) { }
        void show_menu();
        void list_publications();
        void help();
        void list_patrons();

        class Invalid_transaction { };
    private:
        Library& library;
};

#endif