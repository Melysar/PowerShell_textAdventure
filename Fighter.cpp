#include "Fighter.h"

void Fighter::createClass()
{
	string newName = this->getCharacterName() + " The Fighter";

	this->setCharacterName(newName);
}
