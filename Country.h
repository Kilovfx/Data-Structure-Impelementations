#ifndef Country_H
#define Country_H

#include <string>
using namespace std;

// Country structure
struct Country {

string name;
double x,y;
int population;

//Constructor of data Country
Country(const string &countryname, double xCoord, double yCoord, int countryPopulation) : name(Countryname), x(xCoord),y(yCoord),population(countryPopulation) {}
//Data Intialization 
Country() : name("empty"), x(0.0), y(0.0), population(0) {}
}

#endif // COUNTRY_H
