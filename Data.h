#ifndef DATA_H
#define DATA_H

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
    void deleteCityByCoordinates(double xCoord, double yCoord);
    //search function
    int binarySearchByName(const string& countryName);
    int binarySearchByCoordinates(double xCoord, double yCoord);
    // Displays all countries
    void display();
    //functions to limit the errors
    bool isEmpty();
    bool isExist(const string& countryName);

};

#endif // COUNTRYMANAGER_H
