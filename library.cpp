#include "library.h"

void Library::add_publication(Publication pub) {
    publications.push_back(pub);
}

int Library::number_of_publications(){
    return publications.size();
}

string Library::publication_to_string(int publication_index){
    return publications[publication_index].to_string();
}

void Library::check_out(int pub_index, string pat_name, string pat_phone){
    publications[pub_index].check_out(pat_name, pat_phone);
}

void Library::check_in(int pub_index){
    publications[pub_index].check_in();
}

void Library::add_patron(Patron pat){
    patrons.push_back(pat);
}

int Library::number_of_patrons(){
    return patrons.size();
}

string Library::patrons_to_string(int pat_index){
    return patrons[pat_index].to_string();
}

void Library::test() {
 add_publication(Publication("The Firm", "John Grisham", "1991", "0440245923", Genre::fiction, Media::book, Age::adult));
 add_publication(Publication("Foundation", "Isaac Asimov", "1942", "0385177259", Genre::fiction, Media::book, Age::adult));
 add_publication(Publication("Foundation and Empire", "Isaac Asimov", "1943", "0385177259", Genre::fiction, Media::book, Age::adult));
 add_publication(Publication("Second Foundation", "Isaac Asimov", "1944", "0385177259", Genre::fiction, Media::book, Age::adult));
 add_publication(Publication("War of the Worlds", "Jeff Wayne", "1977", "9780711969148", Genre::performance, Media::audio, Age::teen));
 add_publication(Publication("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971", "0142410314", Genre::performance, Media::video, Age::children));
}