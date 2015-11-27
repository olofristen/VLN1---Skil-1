#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct person;
void reading_person();
void readDatabase(vector<person>& v);
void welcome();
void choices();
void displayDatabase(vector<person> v);

struct person
{   string name;
    string gender;
    int birthYear;
    int deathYear;
};

vector<person> v(10);

int main()
{
    char check = 'y';

    welcome();

    do{
        choices();

        cout << endl;
        cout << "Do you wish to continue? (Y/N) " << endl;
        cin >> check;

    } while(check == 'y' | check == 'Y');
}

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
            reading_person(v);
            break;
        case 2:
            cout << "List of all computer scientists registered" << endl;
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
    file.open("database.txt", ios::out | ios::app);

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
            file << temp << endl << endl;

            cout << endl;
        }
    }
    else
        cout << "Unable to open file";

    file.close();

}

void readDatabase(vector<person>& v)
{
    ifstream file;
    file.open("database.csv");

    if(file.is_open())
    {
        while(!file.eof())
        {
            cout << "Go into the read!" << endl;
            person a;
            string tempBirth, tempDeath;
            getline(file, a.name);
            getline(file, a.gender);
            getline(file, tempBirth);
            getline(file, tempDeath);
            a.birthYear = atoi(tempBirth.c_str());
            a.deathYear = atoi(tempDeath.c_str());
            cout << "Done reading" << endl;
            v.push_back(a);
        }
    }
    else
        cout << "Unable to open file" << endl;

    file.close();

}

void displayDatabase(vector<person> v)
{
    cout << "I go into display Database..." << endl;
    for(unsigned int i = 0; (v.size()-1) > i; i++)
    {
        cout << "Name: " << v[i].name << endl;
        cout << "Gender: " << v[i].gender << endl;
        cout << "Year of birth: " << v[i].birthYear << endl;
        cout << "Year of death: " << v[i].deathYear << endl << endl;
    }
}

