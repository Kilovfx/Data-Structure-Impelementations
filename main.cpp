#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <filesystem>

using namespace std;

void displayMenu()
{
    cout << "\nCountry Database Menu:\n";
    cout << "1. Insert a country\n";
    cout << "2. Delete a country\n";
    cout << "3. Search for a country\n";
    cout << "4. Sort countries\n";
    cout << "5. Find Distance between two countries\n";
    cout << "6. Find the nearest countries to a specific country\n";
    cout << "7. Display all countries\n";
    cout << "8. Save countries to file\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
