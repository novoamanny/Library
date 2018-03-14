 #ifndef __PUBLICATION_H
 #define __PUBLICATION_H

 #include <iostream>
 #include <string>

 using namespace std;

 class Publication {
     public:
     Publication(string p_title, 
                 string p_author, 
                 string p_copyright,
                 string p_isbn) : 

                 title(p_title), 
                 author(p_author),
                 copyright(p_copyright), 
                 isbn(p_isbn), 
                 patron_name(""),
                 patron_phone(""),
                 checked_out(false) { }

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
 };

 #endif