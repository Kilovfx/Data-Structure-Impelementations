#ifndef DATA_H
#define DATA_H

#include "Country.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class Data {
private:
    vector<Country> countries;

public:
    // Constructor and Destructor
    Data();
    ~Data();

    // Adds a new country
    void insertCountry(const Country& country);

    // Deletes a country by name
    void deleteCountry(const string& countryName);

    // Deletes a country by coordinates
    void deleteCityByCoordinates(double xCoord, double yCoord);

    // Search functions
    int binarySearchByName(const string& countryName);
    int binarySearchByCoordinates(double xCoord, double yCoord);

    // Sort functions
    void quickSortByName(int left, int right);
    void quickSortByPopulation(int left, int right);

    // Display functions
    void display() const;

    //distance functions
    double distance();
    void findNearestCountry(const string& countryName, int n);

    // Functions to limit errors
    bool isEmpty() const;
    bool isCountryExist(const string& countryName) const;
    bool isCoordinatesExist(double xCoord, double yCoord) const;
    // File saving
    void saveCountryToFile(const vector<Country>& countries, const string& filename);
};

#endif // DATA_H
