 #ifndef __PUBLICATION_H
 #define __PUBLICATION_H

 #include <iostream>
 #include <string>
 #include "age.h"
 #include "media.h"
 #include "genre.h"

 using namespace std;

 class Publication {
     public:
     Publication(string p_title, 
                 string p_author, 
                 string p_copyright,
                 string p_isbn,
                 Genre p_target_genre,
                 Media p_target_media,
                 Age p_target_age) : 

                 title(p_title), 
                 author(p_author),
                 copyright(p_copyright), 
                 isbn(p_isbn), 
                 patron_name(""),
                 patron_phone(""),
                 checked_out(false),
                 target_genre(p_target_genre),
                 target_media(p_target_media),
                 target_age(p_target_age) { }

        string to_string();
        bool is_checked_out();
        void check_out(string pat_name, string pat_phone);
        void check_in();

        class Invalid_transaction { };

     private:
        string title;
        string author;
        string copyright;
        string isbn;
        string patron_name;
        string patron_phone;
        bool checked_out;
        Age target_age;
        Media target_media;
        Genre target_genre;   
 };

 #endif