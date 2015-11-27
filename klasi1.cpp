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
        Person();
        Person(string name, string gender, int birthYear, int deathYear);
        void readData();
        void update();
        void displayData();
        
};
