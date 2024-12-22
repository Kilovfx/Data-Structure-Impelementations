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

//End of insert function



//delete Country name
void Data::deleteCountry(const string& countryName) {
    if (!isExist(countryName)) { // Check if the country exists
        cout << "Error: Country \"" << countryName << "\" not found.\n";
        return; // Exit if the country does not exist
    }

    for (int i = 0; i < countries.size(); ++i) {
        if (countries[i].name == countryName) { // Find the country
            countries.erase(countries.begin() + i); // Delete it
            cout << "Country \"" << countryName << "\" deleted successfully.\n";
            return; // Exit after deleting
        }
    }
}
//End of delete function


//isEmpty Checking function --------
bool Data::isEmpty() const {
    return countries.empty();
}



//isExist Checking function
bool Data::isExist(const string& countryName) const {
    //for loop condition for country list
    for (int i = 0; i < countries.size(); ++i) {
        //checking if new name already exist
        if (country[i].name == countryName) {
            cout << "Error: Country \"" << countryName << "\" already exists.\n";
            return true; // Indicates that the country exists
        }
    }
    return false; // Indicates the country does not exist
}
//End of isExist function


//display the Countries
void Data::display() const {
    if (isEmpty()) {
        cout << "Country database is empty." << endl;
        return;
    }

    cout << "Countries in the database:" << endl;
    //for loop condition for country list
    for (int i = 0; i < countries.size(); ++i) {
        cout << "Name: " << country[i].name
             << ", Coordinates: (" << country[i].x << ", " << country[i].y << ")"
             << ", Population: " << country[i].population << endl;
    }
}

//End of display function
