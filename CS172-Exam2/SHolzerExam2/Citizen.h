#pragma once
//Sam Holzer
//I affirm that all code given below was written solely by me, Sam Holzer, and that any help I received 
//adhered to the rules stated for this exam
#include <string>
using namespace std;

class Citizen
{
private:
	int id;
	string firstName;
	string lastName;
	string color;

public:
	//Constructors to either make a new Citizen with passed characteristics, or copies a Citizen over using a passed Citizen
	Citizen(int id, string firstName, string lastName, string color);
	Citizen(Citizen* citizen);

	//Accessors
	string getFirstName();
	string getLastName();
	int getId();
	string getFavoriteColor();

	//Can only change the favorite color of a Citizen
	void setFavoriteColor(string color);
};