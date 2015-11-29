#include <QCoreApplication>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Person
{
    private:
        string name;
        string gender;
        int birthYear;
        int deathYear;

    public:
        Person();
        Person (string name, string gender, int birthYear, int deathYear);
        //void welcome();
        //void choices();
        void readData(ifstream& file);
        void displayData();
        void searchData();
        void sortData();
        void update();
        string getname();
        string getgender();
        int getbirthyear();
        int getdeathyear();

        friend bool sortbyyearofbirth (const Person& a, const Person &b);
        friend bool sortbyyearofdeath (const Person& a, const Person &b);
        friend bool sortbygender (const Person& a, const Person &b);
        bool operator < (const Person& r);


};


void reading_person();
void readDatabase(vector<Person>& v);
void welcome();
void choices(vector<Person>& v);
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

void choices(vector<Person>& v)
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
            readDatabase(v);
        //    displayDatabase(v);
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

void readDatabase(vector<Person>& v)
{
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
    displayDatabase(v);

}

void displayDatabase(vector<Person>& v)
{
    for(unsigned int i = 0; i < (v.size()-1); i++)
    {
        cout << endl;
        v[i].displayData();
    }
}


int main()
{

    vector<Person> vec;
    char check = 'y';

    welcome();

    do{
        choices(vec);

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
bool Person::operator < (const Person &r) {
     return this->name < r.name;
 }

bool sortbyyearofbirth (const Person& a, const Person &b) {
    return a.birthYear < b.birthYear;
}

bool sortbygender (const Person& a, const Person &b) {
    return a.gender < b.gender;
}
bool sortbyyearofdeath (const Person& a, const Person &b) {
    return a.deathYear < b.deathYear;
}

Person::Person()
{
    name = " ";
    gender = " ";
    birthYear = 0;
    deathYear = 0;
}

Person::Person(string name, string gender, int birthYear, int deathYear)
{
    this->name = name;
    this->gender = gender;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
}


void Person::readData(ifstream& file)
{
    string tempBirth, tempDeath;
    getline(file, name);
    getline(file, gender);
    getline(file, tempBirth);
    getline(file, tempDeath);
    birthYear = atoi(tempBirth.c_str());
    deathYear = atoi(tempDeath.c_str());

}

string Person::getname() {
    return name;
}
string Person::getgender() {
    return gender;
}
int Person::getbirthyear() {
    return birthYear;
}
int Person::getdeathyear() {
    return deathYear;
}
void Person::displayData()
{
    cout << "Name: " << getname() << endl
    << "Gender: " << getgender() << endl
    << "Year of birth: " << getbirthyear() << endl
    << "Year of death: " << getdeathyear() << endl;
}

void Person::searchData()
{

}

void Person::update()
{

}
