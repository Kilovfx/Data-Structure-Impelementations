#include "Data.h"


Data::Data() {
    cout << "Data initialized.\n";
}

Data::~Data() {
    cout << "Data destroyed. Clearing resources...\n";
    countries.clear();
}

//insert function
void Data::insertCountry(const Country& country) {
    //Checking for country name empty 
    if (country.name.empty()) {
        cout << "Error: Country name cannot be empty.\n";
        return;
    }
    //Checking if the name already exist
    if (isExist(country.name)) {
        cout << "Error: Country  |" << country.name << " | already exists in the database.\n";
        return;
    }
    //insert a new country
    countries.push_back(country);
    cout << "Country   |" << country.name << "|  added successfully.\n";
}


//isEmpty Checking function
bool Data::isEmpty() const {
    return countries.empty();
}

//isExist Checking function
bool Data::isExist(const string& countryName) const {
    //for loop condition for country list
    for (const auto& country : countries) {
        //checking if new name already exist
        if (country.name == countryName) {
            cout << "Error: Country \"" << countryName << "\" already exists.\n";
            return true; // Indicates that the country exists
        }
    }
    return false; // Indicates the country does not exist
}
//display the Countries
void Data::display() const {
    if (isEmpty()) {
        cout << "Country database is empty." << endl;
        return;
    }

    cout << "Countries in the database:" << endl;
    //for loop condition for country list
    for (const auto& country : countries) {
        cout << "Name: " << country.name
             << ", Coordinates: (" << country.x << ", " << country.y << ")"
             << ", Population: " << country.population << endl;
    }
}
