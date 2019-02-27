#include "Player.h"
#include <string>
using namespace std;

/****************************************************************************
PLAYER CONSTRUCTORS
****************************************************************************/
Player::Player()
{
	this->setCharacterName("Player");

	this->setLevel(1);

	this->setStrength(10);
	this->setDexterity(10);
	this->setConstitution(10);
	this->setIntelligence(10);
	this->setWisdom(10);
	this->setCharisma(10);

	this->setWeapon("Weapon", 1);

	this->setHead("Head", 0);

	this->setChest("Chest", 0);

	this->setLegs("Legs", 0);

	this->setFeet("Feet", 0);

	this->setHealth();
}

Player::Player(string characterNameValue, int levelValue,
	int strengthValue, int dexterityValue, int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue,
	weapon weaponValue, head headValue, chest chestValue, legs legsValue, feet feetValue)
{
	this->setCharacterName(characterNameValue);

	this->setLevel(levelValue);

	this->setStrength(strengthValue);
	this->setDexterity(dexterityValue);
	this->setConstitution(constitutionValue);
	this->setIntelligence(intelligenceValue);
	this->setWisdom(wisdomValue);
	this->setCharisma(charismaValue);

	this->setWeapon(weaponValue.name, weaponValue.damage);
	this->setHead(headValue.name, headValue.armor);
	this->setChest(chestValue.name, chestValue.armor);
	this->setLegs(legsValue.name, legsValue.armor);
	this->setFeet(feetValue.name, feetValue.armor);

	this->setHealth();
}

/****************************************************************************
PLAYER MUTATORS
****************************************************************************/
void Player::setCharacterName(std::string characterNameValue)
{
	this->characterName = characterNameValue;
}

void Player::setLevel(int levelValue)
{
	if (levelValue > 1)
	{
		this->level = levelValue;
	}
	else
	{
		this->level = 1;
	}
}

void Player::setHealth()
{
	if (this->constitution > 0)
	{
		this->health = (this->constitution * 1.5);
	}
	else
	{
		this->health = 10;
	}
}

void Player::setStrength(int strengthValue)
{
	if (strengthValue >= 1 || strengthValue <= 20)
	{
		this->strength = strengthValue;
	}
	else if (strengthValue < 1)
	{
		this->strength = 1;
	}
	else
	{
		this->strength = 20;
	}
}

void Player::setDexterity(int dexterityValue)
{
	if (dexterityValue >= 1 || dexterityValue <= 20)
	{
		this->dexterity = dexterityValue;
	}
	else if (dexterityValue < 1)
	{
		this->dexterity = 1;
	}
	else
	{
		this->dexterity = 20;
	}
}

void Player::setConstitution(int constitutionValue)
{
	if (constitutionValue >= 1 || constitutionValue <= 20)
	{
		this->constitution = constitutionValue;
	}
	else if (constitutionValue < 1)
	{
		this->constitution = 1;
	}
	else
	{
		this->constitution = 20;
	}
}

void Player::setIntelligence(int intelligenceValue)
{
	if (intelligenceValue >= 1 || intelligenceValue <= 20)
	{
		this->intelligence = intelligenceValue;
	}
	else if (intelligenceValue < 1)
	{
		this->intelligence = 1;
	}
	else
	{
		this->intelligence = 20;
	}
}

void Player::setWisdom(int wisdomValue)
{
	if (wisdomValue >= 1 || wisdomValue <= 20)
	{
		this->wisdom = wisdomValue;
	}
	else if (wisdomValue < 1)
	{
		this->wisdom = 1;
	}
	else
	{
		this->wisdom = 20;
	}
}

void Player::setCharisma(int charismaValue)
{
	if (charismaValue >= 1 || charismaValue <= 20)
	{
		this->charisma = charismaValue;
	}
	else if (charismaValue < 1)
	{
		this->charisma = 1;
	}
	else
	{
		this->charisma = 20;
	}
}

void Player::setWeapon(string weaponName, int weaponDamage)
{
	this->playerWeapon.name = weaponName;

	if (weaponDamage > 0)
	{
		this->playerWeapon.damage = weaponDamage;
	}
	else
	{
		this->playerWeapon.damage = 1;
	}
}

void Player::setHead(string headName, int headArmor)
{
	this->playerHead.name = headName;

	if (headArmor >= 0)
	{
		this->playerHead.armor = headArmor;
	}
	else
	{
		this->playerHead.armor = 0;
	}
}

void Player::setChest(string chestName, int chestArmor)
{
	this->playerChest.name = chestName;

	if (chestArmor >= 0)
	{
		this->playerChest.armor = chestArmor;
	}
	else
	{
		this->playerChest.armor = 0;
	}
}

void Player::setLegs(string legsName, int legsArmor)
{
	this->playerLegs.name = legsName;

	if (legsArmor >=0)
	{
		this->playerLegs.armor = legsArmor;
	}
	else
	{
		this->playerLegs.armor = 0;
	}
}

void Player::setFeet(string feetName, int feetArmor)
{
	this->playerFeet.name = feetName;

	if (feetArmor >= 0)
	{
		this->playerFeet.armor = feetArmor;
	}
	else
	{
		this->playerFeet.armor = 0;
	}
}


/*****************************************************************************
PLAYER OVERLOADED OPERATORS
*****************************************************************************/
ostream& operator<< (ostream& os, const Player& plyr)
{
	os << plyr.characterName << endl;

	for (int i = 0; i < 80; i++)
	{
		os << "=";
	}
	os << endl;

	return os;
}
