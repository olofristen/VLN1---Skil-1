#ifndef DOMAIN_H
#define DOMAIN_H

#include "data.h"
#include <algorithm>
//#include <cstdlib>

class Domain {

// Domain-klasinn geymir vektor með Person-klösum og sér um að umraða, leita í og bæta í hann.  Geymir Database-klasa og
// kemur gögnunum þannig á milli notendaviðmótsins og gagnagrunnsins.

private:

    vector<Person> v;
    Database DB;

public:
    Domain();
    void add_new_person(string name, string gender, int birthyear, int deathyear, string bio);
    void sort_and_display(char sortMenu);
    void displayDatabase();
    void searchstring(char num, string search) ;
    int size();

};


#endif // DOMAIN_H

