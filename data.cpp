#include <fstream>
#include <vector>
#include "person.h"
#include "data.h"

// Database layer (ifstream/ofstream,read/write,...)


vector<Person> Database::read_from_DB()
{
    vector<Person> v;

    ifstream file;
    file.open("database.csv");

    if(file.is_open())
    {
        while(!file.eof())
        {
            Person a;
            a.readData(file);       //

            v.push_back(a);
        }
        v.erase(v.end()-1);     //Skip the last newline ('\n') character, it would make a new (empty) person class
    }
    else
        cerr << "Unable to open file" << endl;

    file.close();
    return v;

}

void Database::write_to_DB(vector<Person> v)
{
    ofstream file;
    file.open("database.csv", ios::out);

    if(file.is_open())
    {
        for(unsigned int i = 0; i < v.size(); i++) {

            file << v[i].getname() << endl;
            file << v[i].getgender() << endl;
            file << v[i].getbirthyear() << endl;
            file << v[i].getdeathyear() << endl;
            file << v[i].getbio() << endl;
        }

    }
    else
        cerr << "Unable to open file";

    file.close();
}
