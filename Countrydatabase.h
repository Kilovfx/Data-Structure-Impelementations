#ifndef DATA_H
#define DATA_h

#include "Country.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Data {
private:
    vector<Country> countries;

public:
    // Adds a new country
    void insert(const Country& country);

    // Deletes a country by name
    void deleteCountry(const string& countryName);

    // Displays all countries
    void display();
};

#endif // COUNTRYMANAGER_H
