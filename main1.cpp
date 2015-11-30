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
void displayDatabase(vector<Person>& v);


void welcome()
{
    cout << "===================================" << endl;
    cout << "|             WELCOME             |" << endl;
    cout << "|               to                |" << endl;
    cout << "|     the Computer Scientist      |" << endl;
    cout << "|             Database            |" << endl;
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
            cout << "Register new computer scientist/s" << endl;
            reading_person();
            break;
        case 2:
            cout << "List of all computer scientists registered" << endl;
            readDatabase();
            break;
        case 3:
            cout << "Search" << endl;
            break;
    }
}

void reading_person()
{
    int number;

    cout << "How many persons? ";
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

}

