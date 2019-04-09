#include<iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct person
{
    string name;
    float weight;
    string location;
    string color;
};
//inside main
int main(void)
{
    vector<person> people;
    string wt;
    person p;
    ifstream in("data.txt");
    while( getline(in,p.name,',') )
    {
        getline(in,wt,',');
        p.weight = (float)atof(wt.c_str());
        getline(in,p.location,',');
        getline(in,p.color);
        people.push_back(p);
    }
//
// now just display all the data in the vector
//
    vector<person>::iterator it = people.begin();
    for(; it != people.end(); it++)
    {
        cout << (*it).name << ", "
            << (*it).weight << ", "
            << (*it).location << ", "
            << (*it).color << "\n";

    }
    return 0;
}
