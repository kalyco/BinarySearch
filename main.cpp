#include "TaxiDriver.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readNYCTaxiDrivers(Array<NYCTaxiDriver>& aTaxiDrivers)
{
  ifstream ifs("nyc_taxi_drivers.txt");
  string line;
  // read the heading away
  getline(ifs, line);
  // unsigned int count = 0;
  while(getline(ifs, line)) {
    // line contains the relevant portion of each line 
    // read from the file
    size_t firstSpacePos = line.find("\t");
    string medNumStr = line.substr(0, firstSpacePos);
    size_t firstCommaPos = line.find(",");
    // Skip the doublequote
    string lastName = line.substr(firstSpacePos + 2, firstCommaPos - firstSpacePos - 2);
    string substrStartingComma = line.substr(firstCommaPos);
    size_t secondQuotesPos = substrStartingComma.find("\"");
    string firstName = substrStartingComma.substr(1, secondQuotesPos-1);
    unsigned int medNo = atoi(medNumStr.c_str());
    NYCTaxiDriver taxiDriver(medNo, lastName, firstName);
    // aTaxiDrivers[count++] = taxiDriver;
    aTaxiDrivers.add(taxiDriver);
  }
}


void findAllMatchingLastName(const Array<NYCTaxiDriver>& aTaxiDrivers, 
		     const string aLastName,
		     Array<NYCTaxiDriver>& aMatchedDrivers)
{
  cout << "array 1" << aTaxiDrivers[0] << endl;
  cout << "array 2" << aLastName << endl;
  cout << "array 3" << aMatchedDrivers[0] << endl;
}

int binarySearch(const Array<NYCTaxiDriver>& aSortedList,
		  unsigned int aKey,
		  int aBegin,
		  int aEnd
		  ) 
{
  // Your code goes here
}

void simpleSortByMedallionNumber(Array<NYCTaxiDriver>& aMatchedDrivers)
{
  // Your code goes here
}

void getAllManhattanMedallions(Array<unsigned int>& aManhattanMedallions)
{
  ifstream ifs("nyc_medallion_numbers_traveling_in_manhattan.txt");
  string line;
  while(getline(ifs, line)) {
    unsigned int medNo = atoi(line.c_str());
    aManhattanMedallions.add(medNo);
  }
}

void printTheMatchingDrivers(const Array<unsigned int>& aManhattanMedallions,
			    const Array<NYCTaxiDriver>& aMatchedDrivers)
{
  // Your code goes here
}

int main()
{
  Array<NYCTaxiDriver> allDrivers;
  // Get all drivers
  readNYCTaxiDrivers(allDrivers);
  cout << "Total number of legal taxi drivers = " 
       << allDrivers.getSize() << endl;
  // cout << allDrivers << endl;
  cout << "---------------------" << endl;

  Array<NYCTaxiDriver> matchedDrivers;
  // Match all the drivers with the last name "SINGH"
  // (Complexity: n)
  findAllMatchingLastName(allDrivers, "SINGH", matchedDrivers);
  cout << "Total matching drivers = " 
       << matchedDrivers.getSize() << endl;
  // Sort the matched drivers (complexity: k^2)
  simpleSortByMedallionNumber(matchedDrivers);
  // cout << matchedDrivers << endl;
  cout << "---------------------" << endl;

  Array<unsigned int> manhattanMedallions;
  // Get the medallion numbers of taxis that traveled Manhattan
  // that day (complexity: m)
  getAllManhattanMedallions(manhattanMedallions);
  cout << "Total number of taxis traveling in Manhattan = " 
       << manhattanMedallions.getSize() << endl;
  // cout << manhattanMedallions << endl;
  cout << "---------------------" << endl;

  // Match and print the drivers
  // (Complexity: m * log k)
  printTheMatchingDrivers(manhattanMedallions, matchedDrivers);
  return 0;
}
