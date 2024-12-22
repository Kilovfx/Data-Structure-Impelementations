#ifndef DATA_H
#define DATA_H

#include "Country.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
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
    //sorts
    void quickSortbyName(int left, int right);
    void quickSortByPopulation(int left, int right);
    // Displays - Cal distance
    void display();
    double distance(double result);
    //functions to limit the errors
    bool isEmpty();
    bool isExist(const string& countryName);
    //files 
    void saveCountryToFile(const vector<Country>& countries, const string &filename);

};

#endif // COUNTRYMANAGER_H
