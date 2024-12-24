#include <iostream>
#include <string>
#include "Data.h"  // Include the Data class header
#include "Country.h" // Include the Country struct header

using namespace std;

void displayMenu();

int main() {
    Data data;  // Create an instance of Data to manage countries
    int choice;
    
    do {
        // Show the menu
        displayMenu();
        cin >> choice;
        
        cin.ignore(); // To clear the input buffer

        string countryName;
        double xCoord, yCoord;
        int population;
        int n;  // For nearest countries
        Country newCountry;

        switch (choice) {
            case 1: // Insert a country
                cout << "Enter country name: ";
                getline(cin, countryName);
                cout << "Enter x coordinate: ";
                cin >> xCoord;
                cout << "Enter y coordinate: ";
                cin >> yCoord;
                cout << "Enter population: ";
                cin >> population;
                newCountry = {countryName, xCoord, yCoord, population};
                data.insertCountry(newCountry);
                break;

            case 2: // Delete a country
                cout << "Enter country name to delete: ";
                getline(cin, countryName);
                data.deleteCountry(countryName);
                break;

            case 3: // Search for a country
                cout << "Enter country name to search: ";
                getline(cin, countryName);
                data.binarySearchByName(countryName);
                break;

            case 4: // Sort countries
                cout << "Choose sort method:\n";
                cout << "1. Sort by name\n";
                cout << "2. Sort by population\n";
                cout << "Enter your choice: ";
                int sortChoice;
                cin >> sortChoice;
                if (sortChoice == 1) {
                    data.quickSortByName(0, data.getCountries().size() - 1); // Adjusted for sorting by name
                } else if (sortChoice == 2) {
                    data.quickSortByPopulation(0, data.getCountries().size() - 1); // Adjusted for sorting by population
                }
                break;

            case 5: // Find distance between two countries
                cout << "Enter name of the first country: ";
                getline(cin, countryName);
                cout << "Enter name of the second country: ";
                getline(cin, countryName);
                data.distance(); // Adjust as needed
                break;

            case 6: // Find nearest countries to a specific country
                cout << "Enter country name to find nearest countries: ";
                getline(cin, countryName);
                cout << "Enter the number of nearest countries to find: ";
                cin >> n;
                data.findNearestCountry(countryName, n);
                break;

            case 7: // Display all countries
                data.display();
                break;

            case 8: // Save countries to a file
                cout << "Enter filename to save countries: ";
                string filename;
                getline(cin, filename);
                data.saveCountryToFile(data.getCountries(), filename);
                break;

            case 0: // Exit
                cout << "Exiting program. Goodbye!\n";
                break;

            default: // Invalid choice
                cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (choice != 0);  // Repeat until user chooses to exit

    return 0;
}
