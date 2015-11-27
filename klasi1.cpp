#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
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
        void readData();
        void displayData();
        void searchData();
        void sortData();
        void update();

        bool operator < (const Person& r);


};
void welcome();
void choices();

int main()
{
    vector<Person> vec;

    welcome();
    choices();

    vec.push_back(Person("I","kk",1738,2984));

    vec.push_back(Person("E","kk",1738,234));

    vec.push_back(Person("U","kk",1738,234));

    vec.push_back(Person("B","kk",1738,234));

    vec.push_back(Person("A","kk",63,2984));

    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.begin(), vec.end());

    cout <<endl << "Sorted alphabetically (ascending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }
    sort(vec.rbegin(), vec.rend());

    cout <<"Sorted alphabetically (descending): "<<endl<<endl;
    for(int i = 0; i < vec.size(); i++) {
        vec[i].displayData();
    }


}
bool Person::operator < (const Person &r) {
     return this->name < r.name;
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
            //reading_person(v);
            break;
        case 2:
            cout << "List of all computer scientists registered" << endl;
            break;
        case 3:
            cout << "Search" << endl;
            break;
    }
}
void Person::readData()
{
    cout << "Name: ";
    cin >> name;
    cout << "Gender (F/M): ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> birthYear;
    cout << "Year of death: ";
    cin >> deathYear;
}
void Person::displayData()
{
    cout << "Name: " << name << endl
    << "Gender: " << gender << endl
    << "Year of birth: " << birthYear << endl
    << "Year of death: " << deathYear << endl;
}
void Person::searchData()
{

}
void Person::sortData()
{

}
void Person::update()
{

}
