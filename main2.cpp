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
void searchDatabase();


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

    /*if (menu != '1' || menu != '2' || menu != '3')  // virkar ekki af e-h ástæðu...
    {
        do
        {
            cout << "This option is not available. Please enter an available option: ";
            cin >> menu;
        }
        while (menu != '1' || menu != '2' || menu != '3');
    }*/

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
            searchDatabase();
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
        default:
            sort(v.begin(), v.end());
            break;
        case '2':
            sort(v.rbegin(), v.rend());
            break;
        /*case '3':
            sort(v.begin(), v.end(), sortbygender);  //fæ not declared in this scope
            break;
        case '4':
            sort(v.begin(), v.end(), sortbyyearofbirth);  //fæ not declared in this scope
            break;
        case '5':
            sort(v.begin(), v.end(), sortbyyearofdeath);   //fæ not declared in this scope
            break;*/
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
        v.erase(v.end()-1);

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

void searchDatabase()
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
        //v.erase(v.end()-1);
    }
    else
        cout << "Unable to open file" << endl;

    file.close();
            int searchMenu = 0;
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

            if(searchMenu == 1)
              {
                string search;
                int countM = 0;
                cout << "What name would you like to find?: ";
                cin >> search;
                for(unsigned int i = 0; i < v.size(); i++)
                {
                   if (v[i].getname().find(search) != string::npos)
                   {
                       cout << "We have a match!" << endl;
                       v[i].displayData();
                       countM++;
                   }
                 }
                if(countM == 0)
                   {
                    cout << "sorry, no match.";
                   }
              }
               else if(searchMenu == 2)
                {   string search;
                    int countM = 0;
                    cout << "A lady or a man? or a dog maby?: ";
                    cin >> search;
                    for(unsigned int i = 0; i < v.size(); i++)
                    {
                        if (v[i].getgender().find(search) != string::npos)
                        {
                            cout << "We have a match!" << endl;
                            v[i].displayData();
                            countM++;
                        }
                    }
                  if(countM == 0)
                      {
                       cout << "sorry, no match.";
                       }
                }
                else if(searchMenu == 3)
                    {
                        int search;
                        int countM = 0;
                        cout << "When was the person born?: ";
                        cin >> search;
                        for(unsigned int i = 0; i < v.size(); i++)
                        {
                            if (v[i].getbirthyear()== search)
                            {
                                cout << "We have a match!" << endl;
                                v[i].displayData();
                                countM++;
                            }
                        }
                        if(countM == 0)
                        {
                            cout << "sorry, no match.";
                        }
                    }
                else if(searchMenu == 4)
                        {
                            int search;
                            int countM = 0;
                            cout << "When did the person die?: ";
                            cin >> search;
                            for(unsigned int i = 0; i < v.size(); i++)
                            {
                                if (v[i].getdeathyear()== search)
                                {
                                    cout << "We have a match!" << endl;
                                    v[i].displayData();
                                    countM++;
                                }

                            }
                            if(countM == 0)
                               {
                                cout << "sorry, no match.";
                               }
                         }
                else if(searchMenu == 5)
                            {
                                 string search;
                                 int countM = 0;
                                 cout << "Enter some word and we will see..: ";
                                  cin >> search;
                                   for(unsigned int i = 0; i < v.size(); i++)
                                   {
                                       if (v[i].getbio().find(search) != string::npos)
                                       {
                                           cout << "We have a match!" << endl;
                                           v[i].displayData();
                                           countM++;
                                       }
                                    }
                                   if(countM == 0)
                                      {
                                       cout << "sorry, no match.";
                                      }
                             }

}


