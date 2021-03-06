#ifndef UI_H
#define UI_H

#include "domain.h"
// Klasi sem heldur utan um notendaviðmótið.  Notandinn getur t.d. bætt inn nýjum einstakling, lesið alla einstaklingana út
// á skjáinn með ákveðinni röðun og leitað af einverju sem tengist einstaklingnum.

class UI {
private:
    Domain my_dom;

public:
    void welcome();
    void choices();
    void reading_person();
    void sortMessage();
    void registerMessage();
    void searchMessage();
    void searchData();
    void return_home();

};

#endif // UI_H

