#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "pokedex.h"

using namespace std;

//creates an empty pokedex, using a loop to initialize the values in A to nullptr
Pokedex::Pokedex()
{
	for (int i = 0; i < 1000; i++)
	{
		A[i] = nullptr;
	}
}

//Creates a Pokedex with the pokemon found in a given file.
Pokedex::Pokedex(string filename)
{
	string summary;
	int arrayindex;

  //initializes the values in A to nullptr
	for (int i = 0; i < 1000; i++)
	{
		A[i] = nullptr;
	}

  //opens file
	ifstream infile(filename);

  //gets a line from the file and initializes a Pokemon using that line.
  //copies the ndex of the Pokemon into the variable arrayindex
  //places the pointer to the pokemon inside the index equal to the ndex.
	while (getline(infile, summary)) {
		Pokemon* z = new Pokemon(summary);
		arrayindex = z->Ndex();
		A[arrayindex] = z;
	}

  //closes the file
	infile.close();

}

//writes the Pokedex into a file
void Pokedex::save(string filename)
{
	//opens file
  ofstream outfile(filename);
	
  //loops trough the pokedex and writes the Pokemons into the file using the summary() function to convert the Pokemon info into a string.
	for (int i = 0; i < 1000; i++)
	{
		if (A[i] != nullptr) {
			outfile << A[i]->summary() << endl;
		}
	}
  
  //closes the file
	outfile.close();
}

//Adds a Pokemon to the pokedex storing the pointer in the array index equal to the Pokemon ndex.
void Pokedex::add(Pokemon* p)
{
	A[p->Ndex()] = p;
}

//removes a Pokemon from the pokedex by setting the corresponding array index (equal to the pokemon's ndex) to nullptr.
void Pokedex::remove(Pokemon* p)
{
	A[p->Ndex()] = nullptr;
}

//Returns a (pointer to a) pokemon in the pokedex with the given name by looping through the array and checking all the non-nullptr pointers and comparing the names of the pokemons with the given name. If none exists, returns nullptr.
Pokemon* Pokedex::lookup_by_name(string name)
{
	for (int i = 0; i < 1000; i++) {
		if (A[i] != nullptr) {
			if (A[i]->name() == name) {
				return A[i];
			}
		}
	}

	return nullptr;
}

//Returns a (pointer to a) pokemon in the pokedex with the given Ndex. If none exists, returns nullptr.
Pokemon* Pokedex::lookup_by_Ndex(int ndex)
{
	if (A[ndex] != nullptr) {
		return A[ndex];
	}
	
	return nullptr;
}

//return the number of pokemons in the pokedex by looping through the array and counting all the non-nullptr pointers
int Pokedex::size()
{
	int counter = 0;

	for (int i = 0; i < 1000; i++) {
		if (A[i] != nullptr)
		{
			counter++;
		}
	}

	return counter;
}
