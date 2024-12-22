#include "Data.h"

// constructor 
Data::Data() {
    cout << "Data initialized.\n";
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
    //insert as an arraylist
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
        //sequantial search to find . . .
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







    //Search by name function start
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

//end of search by name function -------









  //Search by coordinates function start
int Data::binarySearchByCoordinates(double xCoord, double yCoord) {
    // Check if the country list is empty
    if (isEmpty()) {
        cout << "Error: The country database is empty." << endl;
        return -1; // Indicates that the database is empty
    }

    // Binary Search for the country by coordinates using a for loop
    int left = 0;
    int right = countries.size() - 1;
    for (int i = left; i <= right; i++) {
        
        //condition of binarysearch for mid index
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

//end of search by coordinates function --------









//start of quick sort by name function ----------
void Data::quickSortByName(int left, int right)
{
    // Base case: if the subarray has 1 or 0 elements, it's already sorted.
    if (left >= right) {
        return;
    }

    // Step 1: Choose a pivot. We'll use the middle element of the range.
    int pivotIndex = (left + right) / 2; // Middle element index
    string pivotName = countries[pivotIndex].name;

    // Step 2: Partition the array around the pivot
    int i = left;
    int j = right;
    
    while (i <= j) {
        // Move i to the right until we find an element greater than the pivot
        while (countries[i].name < pivotName) {
            i++;
        }

        // Move j to the left until we find an element smaller than the pivot
        while (countries[j].name > pivotName) {
            j--;
        }

        // If i <= j, swap the elements and move i and j towards the middle
        if (i <= j) {
            swap(countries[i], countries[j]);
            i++;
            j--;
        }
    }

    // Step 3: Recursively apply QuickSort to the left and right subarrays
    if (left < j) {
        quickSortByName(left, j); // Left part
    }
    if (i < right) {
        quickSortByName(i, right); // Right part
    }
}
//end of quick sort by name function 










//start of quick sort by Population function 
void Data::quickSortByPopulation(int left, int right) {
    if (left < right) {
        int pivotIndex = left + (right - left) / 2; // Middle element index
        int pivotPopulation = countries[pivotIndex].population;

        // Partition the array around the pivot
        int i = left;
        int j = right;

        while (i <= j) {
            // Move i to the right while countries[i].population < pivotPopulation
            while (countries[i].population < pivotPopulation)
                i++;

            // Move j to the left while countries[j].population > pivotPopulation
            while (countries[j].population > pivotPopulation)
                j--;

            if (i <= j) {
                // Swap elements
                swap(countries[i], countries[j]);
                i++;
                j--;
            }
        }

        // Recursively sort the subarrays
        if (left < j) {
            quickSortByPopulation(left, j);
        }
        if (i < right) {
            quickSortByPopulation(i, right);
        }
    }
}

//end of quick sort by Population function 












//isExist Checking function
bool Data::isExist(const string& countryName,double xCoord,double yCoord) const {
    //for loop condition for country list
    for (int i = 0; i < countries.size(); ++i) {
        //checking if new name already exist
        if (countries[i].name == countryName) {
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












//start of distance function ---
double Data::distance(double result){
    
    int index1, index2;
        // Display countries for the user to choose from
        cout << "Select two countries to calculate the distance:\n";
        for (int i = 0; i < countries.size(); ++i) {
            cout << i + 1 << ". " << countries[i].name << endl;
        }
        cout << "Enter the number of the first country: ";
        cin >> index1;
        cout << "Enter the number of the second country: ";
        cin >> index2;
    
         // Check if input is valid
        if (index1 < 1 || index1 > countries.size() || index2 < 1 || index2 > countries.size()) {
            cout << "Invalid input! Please choose valid countries.\n";
            return;
        }
            // Get the coordinates of the selected countries
            Country countryA = countries[index1 - 1];
            Country countryB = countries[index2 - 1];

             // Calculate the distance between the two countries using the Euclidean formula
             double result = sqrt((countryB.x - countryA.x) * (countryB.x - countryA.x) +
                                  (countryB.y - countryA.y) * (countryB.y - countryA.y));

             // Output the result
            cout << "Distance between " << countryA.name << " and " << countryB.name << ": " << result << " units.\n";

            return result;
    
}

//end of distance function ---













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











//start of save to file function  : ->
void Data::saveCountryToFile(const vector<Country>& countries, const string &filename){
 //define the txt name   
 ofstream datafile(filename); 
 // Check if the file was opened successfully
    if (!datafile) {
        cout << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    // Write the data of each country to the file using a for loop
    for (int i = 0; i < countries.size(); ++i) {
       datafile << countries[i].name << ","  // Write name
                << countries[i].x << ","  // Write x coordinate
                << countries[i].y << ","  // Write y coordinate
                << countries[i].population << endl;  // Write population
    }

// Close the file
    datafile.close();
    cout << "Countries have been saved to " << filename << " successfully." << endl;
}


//end of save to file function ---





//isEmpty Checking function --------

bool Data::isEmpty() const {
    return countries.empty();
}
//isEmpty Checking function --------



//destrctour 

Data::~Data() {
    cout << "Data destroyed. Clearing resources...\n";
    countries.clear();
}



