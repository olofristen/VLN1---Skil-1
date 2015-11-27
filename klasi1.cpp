#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

class person
{
    private:
        string name;
        string gender;
        int birthYear;
        int deathYear;
    public:
        //Person();
        Person(string name, string gender, int birthYear, int deathYear);
        void readData();
        void displayData();
        void searchData();
        void sortData();
        void update();
        
};

int main()
{   
    Person person;
    int number;
    cout << "How many persons? ";
    cin >> number;
    person.readData();
    
}
void person::readData()
{
    
}
void person::displayData()
{
    
}
void person::searchData()
{
    
}
void person::sortData()
{
    
}
void person::update()
{
    
}
