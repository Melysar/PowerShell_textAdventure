#include <iostream>
#include <fstream>
#include "Player.h"
#include "Fighter.h"
#include "Magician.h"
using namespace std;

/* FUNCTION DEFINITIONS */
void title();
void getNarration(std::string path);
Player * createClass(int choice);

int main()
{
	// VARIABLES
	string stringInput = "";
	int numInput = 0;
	Player * playerCharacter;

	//GAME TITLE
	title();

	// INTRODUCTION
	getNarration("introduction.txt");

	cout << "What is your name traveler?" << endl;

	cout << "Player: ";
	cin >> stringInput;

	// INTRODUCTION 2
	getNarration("introduction_2.txt");
	cout << "Player: ";
	cin >> numInput;

	// CREATE PLAYER CLASS
	playerCharacter = createClass(numInput);
	playerCharacter->setCharacterName(stringInput);
	playerCharacter->createClass();

	cout << endl << playerCharacter;

	return 0;
}


/* FUNCTIONS */
void title()
{
	int spacer = 0;
	string title = "Text Adventure";

	spacer = (80 - title.length()) / 2;

	//Line 1
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < title.length(); i++)
	{
		cout << "=";
	}
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	cout << endl;

	//Line 2
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	cout << title;
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	cout << endl;

	//Line 3
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < title.length(); i++)
	{
		cout << "=";
	}
	for (int i = 0; i < spacer; i++)
	{
		cout << " ";
	}
	cout << std::endl << endl;

}

void getNarration(std::string file)
{
	cout << "================================================================================" << endl;

	string narration = "";
	ifstream narrationFile(file);

	if (narrationFile.is_open())
	{
		while (getline(narrationFile, narration))
		{
			cout << narration << endl;
		}
		narrationFile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}

Player * createClass(int choice)
{
	Player * ptr;

	if (choice == 1)
	{
		ptr = new Fighter;
	}
	else
	{
		ptr = new Magician;
	}

	return ptr;
}
