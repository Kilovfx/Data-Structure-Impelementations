#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

// Country structure
struct Country {
    string name;
    double x, y;
    int population;

    // Constructor for Country data
    Country(const string &countryName, double xCoord, double yCoord, int countryPopulation)
        : name(countryName), x(xCoord), y(yCoord), population(countryPopulation) {}

    // Default Constructor
    Country() : name("empty"), x(0.0), y(0.0), population(0) {}
};

#endif // COUNTRY_H
