#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
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
        //Person (string name, string gender, int birthYear, int deathYear);
        void welcome();
        void readData();
        void displayData();
        void searchData();
        void sortData();
        void update();

};

int main()
{
    Person person;

    person.welcome();

}
Person::Person()
{
    name = " ";
    gender = " ";
    birthYear = 0;
    deathYear = 0;
}
/*Person::Person(string name, string gender, int birthYear, int deathYear)
{
    name = name;
    gender = gender;
    birthYear = birthYear;
    deathYear = deathYear;
}*/
void Person::welcome()
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
void Person::readData()
{

}
void Person::displayData()
{

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
