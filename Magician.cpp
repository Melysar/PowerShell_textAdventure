#include "Magician.h"

void Magician::createClass()
{
	string newName = this->getCharacterName() + " The Magician";

	this->setCharacterName(newName);
}
