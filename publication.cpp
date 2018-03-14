#include "publication.h"
 #include <string>
 #include <iostream>

 using namespace std;

 string Publication::to_string(){
     string pub = "\"" + title + "\"" + " by " + author + ", " + copyright + 
     "ISBN: " + isbn;
   if (checked_out) {
      pub += "\nChecked out to " + patron_name + " (" + patron_phone + ")\n";
   }
   else {
     pub += "\nAvailable!\n";
   }
   return pub;
 }

 bool Publication::is_checked_out(){
     return checked_out;
 }

 void Publication::check_out(string pat_name, string pat_phone){
     if (checked_out){
         throw Invalid_transaction();
     }
     else{
         checked_out = true;
         patron_name = pat_name;
         patron_phone = pat_phone;
     }
 }

 void Publication::check_in(){
     if (checked_out){
         checked_out = false;
     }
     else {
         throw Invalid_transaction();
     }
 }