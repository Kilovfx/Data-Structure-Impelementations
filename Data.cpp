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



//delete CountrybyCooridnates 

void Data::deleteCityByCoordinates(double xCoord, double yCoord) {
    // Check if the database is empty
    if (isEmpty()) {
        cout << "Error: The database is empty. No country to delete." << endl;
        return;
    }

    // Use a loop to find the country with the matching coordinates
    for (int i = 0; i < countries.size(); ++i) {
        if (countries[i].x == xCoord && countries[i].y == yCoord) {
            // Remove the country from the list
            cout << "Country   |" << countries[i].name << "|  at coordinates (" 
                 << xCoord << ", " << yCoord << ") has been deleted." << endl;
            //delete the country that i pointing to ->
            countries.erase(countries.begin() + i);
            return;
        }
    }
    // If no matching country is found
    cout << "Error: No country found at coordinates (" << xCoord << ", " << yCoord << ")." << endl;
}

    //End of CountrybyCooridnates function

    int Data::binarySearchByName(const string& countryName) const {
    // Check if the country list is empty
    if (isEmpty()) {
        cout << "Error: The country database is empty." << endl;
        return -1; // Indicates that the database is empty
    }

    // Binary Search for the country by name using a for loop
    int left = 0;
    int right = countries.size() - 1;

    for (int i = left; i <= right; i++) {
        //condition of binarysearch for mid index
        int mid = left + (right - left) / 2;

        // Check if the country name at mid is equal to the searched name
        if (countries[mid].name == countryName) {
            cout << "Country found at index " << mid << ": " << countries[mid].name
                 << ", Coordinates: (" << countries[mid].x << ", " << countries[mid].y
                 << "), Population: " << countries[mid].population << endl;
            return mid; // Country found, return the index
        }

        // Adjust the search range based on the comparison
        if (countries[mid].name < countryName) {
            left = mid + 1; // Move the left pointer to mid + 1
        } else {
            right = mid - 1; // Move the right pointer to mid - 1
        }
    }

    // If we reach here, the country is not present
    cout << "Error: Country \"" << countryName << "\" not found in the database." << endl;
    return -1; // Indicates that the country was not found
}

int Data::binarySearchByCoordinates(double xCoord, double yCoord) const {
    // Check if the country list is empty
    if (isEmpty()) {
        cout << "Error: The country database is empty." << endl;
        return -1; // Indicates that the database is empty
    }

    // Binary Search for the country by coordinates using a for loop
    int left = 0;
    int right = countries.size() - 1;

    for (int i = left; i <= right; i++) {
        int mid = left + (right - left) / 2;

        // Check if the coordinates at mid match the search coordinates
        if (countries[mid].x == xCoord && countries[mid].y == yCoord) {
            cout << "Country found at index " << mid << ": " << countries[mid].name
                 << ", Coordinates: (" << countries[mid].x << ", " << countries[mid].y
                 << "), Population: " << countries[mid].population << endl;
            return mid; // Country found, return the index
        }

        // Adjust the search range based on the comparison of coordinates
        if (countries[mid].x < xCoord || (countries[mid].x == xCoord && countries[mid].y < yCoord)) {
            left = mid + 1; // Move the left pointer to mid + 1
        } else {
            right = mid - 1; // Move the right pointer to mid - 1
        }
    }

    // If we reach here, the coordinates are not present
    cout << "Error: Country with coordinates (" << xCoord << ", " << yCoord << ") not found." << endl;
    return -1; // Indicates that the country was not found
}






//isEmpty Checking function --------
bool Data::isEmpty() const {
    return countries.empty();
}



//isExist Checking function
bool Data::isExist(const string& countryName,double xCoord,double yCoord) const {
    //for loop condition for country list
    for (int i = 0; i < countries.size(); ++i) {
        //checking if new name already exist
        if (country[i].name == countryName) {
            cout << "Error: Country  |" << countryName << "|  already exists."<<"or the coordinates are exist"<<endl;
            return true; // Indicates that the country exists
        }
        if (countries[i].x == xCoord && countries[i].y == yCoord) {
            cout << "Error: Coordinates (" << xCoord << ", " << yCoord << ") already exist." << endl;
            return true; // Coordinates already exist
        }
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
