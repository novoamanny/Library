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

void Library::test() {
 add_publication(Publication("The Firm", "John Grisham", "1991", "0440245923"));
 add_publication(Publication("Foundation", "Isaac Asimov", "1942", "0385177259"));
 add_publication(Publication("Foundation and Empire", "Isaac Asimov", "1943", "0385177259"));
 add_publication(Publication("Second Foundation", "Isaac Asimov", "1944", "0385177259"));
 add_publication(Publication("War of the Worlds", "Jeff Wayne", "1977", "9780711969148"));
 add_publication(Publication("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971", "0142410314"));
}