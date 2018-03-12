#include "publication.h"
 #include <string>
 #include <iostream>

 using namespace std;

 string Publication::to_string(){
     string pub = "\"" + title + "\"" + " by " + author + ", " + copyright + 
     "ISBN: " + isbn;
   if (checked_out) {
      pub += "\nChecked out to " + patron_name + " (" + patron_phone + ")";
   }
   else {
     pub += "Available!";
   }
   return pub;
 }