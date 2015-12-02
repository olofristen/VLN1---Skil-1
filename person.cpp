#include "person.h"

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
    bio = " ";
}

Person::Person(string name, string gender, int birthYear, int deathYear, string bio)
{
    this->name = name;
    this->gender = gender;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
    this->bio = bio;
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
string Person::getbio() {
    return bio;
}

void Person::displayData()
{
    cout << "Name: " << getname() << endl
         << "Gender: " << getgender() << endl
         << "Year of birth: " << getbirthyear() << endl;
    if(getdeathyear() == -1) {
        cout << "Alive and well!" << endl;
    }
    else {
        cout << "Year of death: " << getdeathyear() << endl;
    }
    cout << "Bio: " << getbio() << endl
         << "------------------------------------------------------------------" << endl;
}

void Person::readData(ifstream& file)
{
    string tempBirth, tempDeath;
    getline(file, name);
    getline(file, gender);
    getline(file, tempBirth);
    getline(file, tempDeath);
    getline(file, bio);
    birthYear = atoi(tempBirth.c_str());
    deathYear = atoi(tempDeath.c_str());
}


