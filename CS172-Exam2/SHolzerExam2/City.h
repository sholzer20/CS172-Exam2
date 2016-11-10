#pragma once
//Sam Holzer
//I affirm that all code given below was written solely by me, Sam Holzer, and that any help I received 
//adhered to the rules stated for this exam
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Citizen.h"
using namespace std;

class City
{
private:
	string cityName;
	int population;
	vector<Citizen> citizens;

public:
	//Constructor accesses a file containing Citizen information and destructor will output all of the citizen information to a file
	City(string cityName);
	~City();

	//Accessors for the member variables. getCitizenAtIndex and getCitizenWithId will search the vector of Citizens for given information
	string getCityName();
	int populationSize();
	Citizen* getCitizenAtIndex(int index);
	Citizen* getCitizenWithId(int id);

	//getCitizensForFavoriteColor returns a vector containing every citizen in the City that has the given favorite color
	vector<Citizen*> getCitizensForFavoriteColor(string color);

	//Adds a Citizen to the vector
	void addCitizen(Citizen* citizen);
};