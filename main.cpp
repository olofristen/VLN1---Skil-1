#include <iostream>
#include <vector>
using namespace std;

struct person;
void reading_person(vector<person> v);

struct person
{   string name;
    string gender;
    int birthYear;
    int deathYear;
};
int main()
{
    vector<person> v(10);
    reading_person(v);
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
