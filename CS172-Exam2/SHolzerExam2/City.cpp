//Sam Holzer
//I affirm that all code given below was written solely by me, Sam Holzer, and that any help I received 
//adhered to the rules stated for this exam
#include "City.h"

City::City(string cityName)
{
	//Concatenate the cityName with .txt to make it a file name. Then opens that file
	string fileName = cityName + ".txt";
	fstream filein(fileName, ios::in | ios::out);

	//If the file doesn't exist, this will create it for the first time
	if (filein.fail())
	{
		cout << "Creating input file for the first time." << endl;
		filein.open(fileName, ios::out);
	}
	//These are all of the properties of a citizen that we want to access
	string line;
	int id;
	string firstName;
	string lastName;
	string color;

	//Reads through each line in the input file (info for one Citizen per line) and takes stores that info in variables
	while (getline(filein, line))
	{
		stringstream ss(line);
		ss >> id;
		ss >> firstName;
		ss >> lastName;
		ss >> color;

		//Creates a new citizen object with the passed variables then adds it to the Citizen vector and deletes the object
		Citizen* citizen = new Citizen(id, firstName, lastName, color);
		citizens.push_back(citizen);
		delete citizen;
	}
	filein.close();

	this->cityName = cityName;
}

City::~City()
{
	//Concatenate the cityName with .txt to make it a file name. Then opens that file
	string fileName = cityName + ".txt";
	ofstream fileout(fileName);

	//If there is an error opening the file, then this error is outputted and the deconstructor stops
	if (fileout.fail())
	{
		cout << "There was an error opening the output file" << endl;
	}

	//This loop creates each line to go in the output file. A line contains the information for one Citizen (id, firstName, lastName, color)
	string line;
	for (unsigned int i = 0; i < (unsigned)(citizens.size()); i++)
	{
		line = to_string(citizens[i].getId()) + " " + citizens[i].getFirstName() + " " + citizens[i].getLastName() + " " + citizens[i].getFavoriteColor();
		fileout << line << endl;
	}

	fileout.close();
}

string City::getCityName()
{
	return cityName;
}

int City::populationSize()
{
	return (unsigned)(citizens.size());
}

Citizen * City::getCitizenAtIndex(int index)
{
	return &(citizens[index]);
}

void City::addCitizen(Citizen * citizen)
{
	//Creates a copy of the passed Citizen and adds it to the Citizen vector. Copying is necessary so that the passed Citizen can be deleted at
	//any time in the main program and City can still keep track of that Citizen.
	Citizen* c1 = new Citizen(citizen);
	citizens.push_back(c1);
	delete c1;
}

Citizen * City::getCitizenWithId(int id)
{
	//Searches through the Citizen vector. If a Citizen has a matching id to the passed id, a pointer to that object is returned
	for (unsigned int i = 0; i < (unsigned)(citizens.size()); i++)
	{
		if (citizens[i].getId() == id)
		{
			return &(citizens[i]);
		}
	}
	//If no Citizen is found with the passed id, a null pointer is returned
	return nullptr;
}

vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	//Creating the new vector to be returned
	vector<Citizen*> citizensFavColor;

	//Searches through the Citizen vector and if a citizen with the same favorite color as the passed one is found, then a pointer to that
	//Citizen is pushed to the back of the new vector
	for (unsigned int i = 0; i < (unsigned)(citizens.size()); i++)
	{
		if (citizens[i].getFavoriteColor() == color)
		{
			citizensFavColor.push_back(&(citizens[i]));
		}
	}

	return citizensFavColor;
}
