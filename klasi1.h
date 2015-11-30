#ifndef KLASI_H
#define KLASI_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
#include<cstdlib>
#include<iomanip>
#include<algorithm>

using namespace std;

class Person
{

    public:
        Person();
        Person (string name, string gender, int birthYear, int deathYear);
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

    private:
        string name;
        string gender;
        int birthYear;
        int deathYear;


};
#endif
