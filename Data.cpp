#include "Data.h"


Data::Data() {
    cout << "Data initialized.\n";
}

Data::~Data() {
    cout << "Data destroyed. Clearing resources...\n";
    countries.clear();
}


void Data::insertCountry(const Country& country) {
  if (country.name.empty()) {
        cout << "Error: Country name cannot be empty.\n";
        return;
    }


  
}
