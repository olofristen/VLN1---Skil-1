#include <QCoreApplication>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include "klasi.h"

using namespace std;

void reading_person();
void readDatabase();
void welcome();
void choices();
void registerMessage();
void sortMessage();
void searchMessage();
void displayDatabase(vector<Person>& v);


int main()
{
    char check = 'y';

    welcome();

    do{
        choices();

        cout << endl;
        cout << "Do you wish to continue? (Y/N) " << endl;
        cin >> check;

    } while(check == 'y' || check == 'Y');



    /*for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.begin(), vec.end());

    cout <<endl << "Sorted alphabetically (ascending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.rbegin(), vec.rend());

    cout <<endl << "Sorted alphabetically (descending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.begin(), vec.end(), sortbyyearofbirth);

    cout <<endl << "Sorted by birthyear (ascending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.begin(), vec.end(), sortbyyearofdeath);

    cout <<endl << "Sorted by deathyear (ascending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.begin(), vec.end(), sortbygender);

    cout <<endl << "Sorted by gender: "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }*/

}

void welcome()
{
    cout << "===================================" << endl;
    cout << "|             WELCOME             |" << endl;
    cout << "|               to                |" << endl;
    cout << "|      the Famous Computing       |" << endl;
    cout << "|         People Database         |" << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "In this program you will be able to register and go through the most known"
         << "computer scientists of all time!" << endl;
    cout << endl;
}

void choices()
{
    int menu = 0;

    cout << "   =================================================================" << endl;
    cout << "   |  What do you want to do?                                      |" << endl;
    cout << "   |    1.  Register new computer scientist/s                      |" << endl;
    cout << "   |    2.  See all computer scientists registered                 |" << endl;
    cout << "   |    3.  Search the database                                    |" << endl;
    cout << "   |  Please enter the number of your choice!                      |" << endl;
    cout << "   =================================================================" << endl;
    cin >> menu;

    switch (menu)
    {
        case 1:
            system("CLS");
            registerMessage();
            reading_person();
            break;
        case 2:
            system("CLS");
            sortMessage();
            readDatabase();
            break;
        case 3:
            cout << "Search" << endl;
            system("CLS");
            searchMessage();
            break;
    }
}

void registerMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     REGISTER NEW COMPUTING GENIUS                             |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;
}

void sortMessage()
{
    int sortMenu = 0;

    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SORT                                       |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;

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

    switch (sortMenu)
    {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
    }
}

void searchMessage()
{
    cout << "   =================================================================" << endl;
    cout << "   |     THE DATABASE - SEARCH                                     |" << endl;
    cout << "   =================================================================" << endl;
    cout << endl;

}

void reading_person()
{
    int number;

    cout << "How many computing geniuses do you want to register? ";
    cin >> number;

    cout << endl << "Type in person: " << endl << endl;

    ofstream file;
    file.open("database.csv", ios::out | ios::app);

    string temp;

    if(file.is_open())
    {
        for(int i = 0; i < number; i++)
        {
            cout << "Name: ";
            cin.ignore();
            getline(cin, temp);
            file << temp << endl;

            cout << "Gender: ";
            cin >> temp;
            file << temp << endl;

            cout << "Year of birth: ";
            cin >> temp;
            file << temp << endl;

            cout << "Year of death: ";
            cin >> temp;
            file << temp << endl;

            cout << "Bio: ";
            cin.ignore();
            getline(cin, temp);
            file << temp << endl;

            cout << endl;
        }
    }
    else
        cout << "Unable to open file";

    file.close();

}

void readDatabase()
{
    vector<Person> v;
    ifstream file;
    file.open("database.csv");

    if(file.is_open())
    {
        while(!file.eof())
        {
            Person a;
            a.readData(file);

            v.push_back(a);
        }
    }
    else
        cout << "Unable to open file" << endl;

    file.close();
    sort(v.begin(), v.end());   //stafrófsröð

    displayDatabase(v);

}

void displayDatabase(vector<Person>& v)
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << endl;
        v[i].displayData();
    }
}
