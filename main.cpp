#include <iostream>
#include <string>
#include "Country.h"      // For the Country class
#include "Data.h"         // For the Data class (which manages the countries)

using namespace std;

void handleInvalidInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a valid number.\n";
}

void displayMenu() {
    cout << "\nCountry Database Menu:\n";
    cout << "1. Insert a country\n";
    cout << "2. Delete a country\n";
    cout << "3. Search for a country\n";
    cout << "4. Sort countries\n";
    cout << "5. Find distance between two countries\n";
    cout << "6. Find the nearest countries to a specific country\n";
    cout << "7. Display all countries\n";
    cout << "8. Save countries to file\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
int main(){

    Data data;
    int choice;

    do(
    displayMenu();
    cin>>choice;
 if (!(cin >> choice))
        {
            handleInvalidInput();
            continue;
        }

    switch (choice){
        case 1:{
            insertCountry();
            break;}
        case 2:{
            
}
