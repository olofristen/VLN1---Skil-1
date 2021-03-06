#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class computer
{
    private:
        string name;
        int buildYear;
        int type;
        bool wasBuilt;
    public:
        Computer();
        Computer(string name, int buildYear, int type, bool wasBuilt);
        void readData(ifstream& file);
        void displayData();
        void searchData();
        string getname();
        int getbuildyear();
        int type();
        bool getwasBuilt();

        friend bool sortbyyearofbuilt(const Computer& a, const Computer &b);
        friend bool sortbytype(const Computer& a, const Computer &b);
        friend bool sortbywasbuilt(const Computer& a, const Computer &b);
        bool operator < (const Computer& r);

        
};

#endif // COMPUTER_H
