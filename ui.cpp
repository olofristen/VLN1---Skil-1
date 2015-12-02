#include "ui.h"

// UI, heldur utan um öll samskipti við notendur, cin, cout, main.... -> samskipti við domain(worker) sem útfærir vektor o.s.frv.
// helstu atriði sem eru í boði: add, sort og printlist, search.


void UI::welcome()
{

    cout << "===================================" << endl;
    cout << "|             WELCOME             |" << endl;
    cout << "|               to                |" << endl;
    cout << "|     the Computer Scientist      |" << endl;
    cout << "|             Database            |" << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "In this program you will be able to register and go through the most known "
         << "computer scientists of all time!" << endl;
    cout << endl;
    cout << "Now, the database includes " << my_dom.size() << " scientist(s)!" << endl << endl;
}

void UI::choices()
{
    string menu = "";

    cout << "   =================================================================" << endl;
    cout << "   |  What do you want to do?                                      |" << endl;
    cout << "   |    1.  Register new computer scientist/s                      |" << endl;
    cout << "   |    2.  See all computer scientists registered                 |" << endl;
    cout << "   |    3.  Search the database                                    |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;
    cin >> menu;

    if(menu.compare("1") == 0){
        system("CLS");
        registerMessage();
        reading_person();
    }
    else if(menu.compare("2") == 0){
        system("CLS");
        sortMessage();
    }
    else if(menu.compare("3") == 0){
        system("CLS");
        searchData();
    }
    else {
        cout << "Invalid input! " << endl;
    }
}

void UI::registerMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     REGISTER NEW COMPUTING GENIUS                             |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;
}

void UI::searchMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SEARCH                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

}

void UI::sortMessage()     // sleppa því að taka inn vektorinn, á ekki að vera hér...
{
    char sortMenu = '0';

    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SORT                                       |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
    cout << "   Press Q/q to exit" << endl << endl;

    cout << "   =================================================================" << endl;
    cout << "   |  How do you want the computing geniuses to appear?            |" << endl;
    cout << "   |    1.  A-Z                                                    |" << endl;
    cout << "   |    2.  Z-A                                                    |" << endl;
    cout << "   |    3.  By gender                                              |" << endl;
    cout << "   |    4.  By year of birth                                       |" << endl;
    cout << "   |    5.  By year of death                                       |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;

    cin >> sortMenu;

    if(sortMenu == 'Q' || sortMenu == 'q') {
        return ;
    }
    my_dom.sort_and_display(sortMenu);
}


void UI::searchData()
{
    char searchMenu = '0';
    searchMessage();

    cout << "   =================================================================" << endl;
    cout << "   |  in which category would you prefer to search?                |" << endl;
    cout << "   |    1.  By name                                                |" << endl;
    cout << "   |    2.  By gender                                              |" << endl;
    cout << "   |    3.  By year of birth                                       |" << endl;
    cout << "   |    4.  By year of death                                       |" << endl;
    cout << "   |    5.  By bio                                                 |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;
    cin >> searchMenu;

    string search;
    if(searchMenu == 'Q' || searchMenu == 'q') {

        return ;
    }

    switch(searchMenu) {
    case '1':
        cout << "What name would you like to find?: ";
        break;
    case '2':
        cout << "A lady or a man? Or maybe a dog?: ";
        break;
    case '3':
        cout << "When was the person born?: ";
        break;
    case '4':
        cout << "When did the person die?: ";
        break;
    case '5':
        cout << "Enter some word and we will see..: ";
        break;
    default:
        cout << "Invalid input! " << endl;
        break;
    }
    cin >> search;
    my_dom.searchstring(searchMenu, search);
}

void UI::reading_person() {

    string number = "";
    int num = 0;

    do{
        cout << "How many computing geniuses do you want to register? ";
        cin >> number;

        if(number == "Q" || number == "q") {
            return;
        }
        num = atoi(number.c_str());
        if(num <= 0) {
            cout << "Invalid input! " << endl;
        }
    } while(num <= 0);

    cout << endl << "Type in person: " << endl << endl;

    string name = "", gender = "", bio = "", year = "", dead = "";
    int birthyear = 0, deathyear = 0;
    string a = "";

    for(int i = 0; i < num; i++)
    {
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        do{
            cout << "Gender (F/M): ";
            cin >> a;

            if(a.compare("f") == 0 || a.compare("F") == 0){
                gender = "Female";
            }
            else if(a.compare("m") == 0 || a.compare("M") == 0){
                gender = "Male";
            }
            else{
                cout << "Invalid input" << endl;
            }
        }while(gender == "");

        do{
            cout << "Year of birth (1700 - 2010): ";
            cin >> year;

            if(year < "1700" || year > "2010") {
                cout << "Invalid input" << endl;
            }
        }while(year < "1700" || year > "2010");

        birthyear = atoi(year.c_str());


        cout << "Is the scientist dead (Y/N)?: " << endl;
        cin >> dead;
        do{
            if(dead.compare("y") == 0 || dead.compare("Y") == 0) {
                cout << "Year of death: ";  // Dauður
                cin >> year;
                deathyear = atoi(year.c_str());
            }
            else if(dead.compare("n") == 0 || dead.compare("N") == 0) {
                deathyear = -1;     // Ekki dauður
            }
            else {          // Ekki vitað, spyr aftur
                cout << "Invalid input! " << endl;
            }
            if(deathyear < birthyear || deathyear > 2015) {
                cout << "Invalid input! " << endl;
            }

        }while(deathyear != -1 && deathyear < birthyear || deathyear > 2015);


        cout << "Bio: ";
        cin.ignore();
        getline(cin, bio);
        cout << endl;

        my_dom.add_new_person(name, gender, birthyear, deathyear, bio);
    }
}

