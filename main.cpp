#include <iostream>
#include <vector>
using namespace std;

struct person;
void reading_person(vector<person> v);
void welcome();
void choices();

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

void reading_person(vector<person> v)
{
    int number;

    cout << "How many persons? ";
    cin >> number;

    cout << endl << "Type in person: " << endl << endl;

    for(unsigned int i = 0; i < number; i++)
    {
        cout << "Name: ";
        cin >> v[i].name;
        cout << "Gender: ";
        cin >> v[i].gender;
        cout << "Year of birth: ";
        cin >> v[i].birthYear;
        cout << "Year of death: ";
        cin >> v[i].deathYear;
        cout<< " "<< endl;
    }

    cout << "Here are your persons: " << endl << endl;

    for(unsigned int i = 0; i < number; i++)
   {
        cout << "Name: " << v[i].name << endl;
        cout << "Gender: " << v[i].gender << endl;
        cout << "Year of birth: " << v[i].birthYear << endl;
        cout << "Year of death: " << v[i].deathYear << endl;
        cout << endl;
   }

}
