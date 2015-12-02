#include "domain.h"



Domain::Domain() {

    v = DB.read_from_DB();
}

int Domain::size() {
    return v.size();
}

void Domain::add_new_person(string name, string gender, int birthyear, int deathyear, string bio) {     // Bætir nýrri persónu inn i vektorinn...

    v.push_back(Person(name, gender, birthyear, deathyear, bio));
    DB.write_to_DB(v);
}

void Domain::sort_and_display(char sortMenu) {       // sorterar vektorinn...

    switch (sortMenu)
    {
    case '1':
        sort(v.begin(), v.end());
        break;
    case '2':
        sort(v.rbegin(), v.rend());
        break;
    case '3':
        sort(v.begin(), v.end());
        sort(v.begin(), v.end(), sortbygender);
        break;
    case '4':
        sort(v.begin(), v.end(), sortbyyearofbirth);
        break;
    case '5':
        sort(v.begin(), v.end(), sortbyyearofdeath);
        break;
    default:
        cout << "Invalid input! " << endl;
    }
    displayDatabase();
}

void Domain::displayDatabase()      // Prentar út vektorinn...
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << endl;
        v[i].displayData();
    }
    cout << size() << " scientists!" << endl;
}


void Domain::searchstring(char num, string search) {

    int countM = 0;
    cout << endl;

    switch (num) {
    case '1':
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getname().find(search) != string::npos)
            {
                v[i].displayData();
                countM++;
            }
        }
        break;
    case '2':
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getgender().find(search) != string::npos)
            {
                v[i].displayData();
                countM++;
            }
        }

        break;
    case '3':
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getbirthyear() == atoi(search.c_str()))
            {
                v[i].displayData();
                countM++;
            }
        }
        break;
    case '4':
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getdeathyear()== atoi(search.c_str()))
            {
                v[i].displayData();
                countM++;
            }
        }
        break;
    case '5':
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].getbio().find(search) != string::npos)
            {
                v[i].displayData();
                countM++;
            }
        }
        break;
    }

    if(countM == 0)
    {
        cout << "Sorry, no match." << endl;
    }
    else {
        cout << countM << " match(es)!" << endl;
    }
}

// Vantar allt sem tengist search...
