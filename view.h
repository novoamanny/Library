#ifndef __VIEW_H
#define __VIEW_H

#include "library.h"

class View {
    public:
        View(Library& lib) : library(lib) { }
        void show_menu();
    private:
        Library& library;
};

#endif