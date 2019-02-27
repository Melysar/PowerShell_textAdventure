#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
	std::string characterName;

	int level;
	int health;

	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	struct weapon
	{
		std::string name;
		int damage;
	};
	weapon playerWeapon;

	struct head
	{
		std::string name;
		int armor;
	};
	head playerHead;

	struct chest
	{
		std::string name;
		int armor;
	};
	chest playerChest;

	struct legs
	{
		std::string name;
		int armor;
	};
	legs playerLegs;

	struct feet
	{
		std::string name;
		int armor;
	};
	feet playerFeet;

public:
	/* CONSTRUCTORS */
	Player();
	Player(string characterNameValue, int levelValue,
		int strengthValue, int dexterityValue, int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue,
		weapon weaponValue, head headValue, chest chestValue, legs legsValue, feet feetValue);

	/* GETTERS */
	std::string getCharacterName() { return this->characterName; }
	int getLevel() { return this->level; }
	int getHealth() { return this->health; }

	int getStrength() { return this->strength; }
	int getDexterity() { return this->dexterity; }
	int getConstitution() { return this->constitution; }
	int getIntelligence() { return this->intelligence; }
	int getWisdom() { return this->wisdom; }
	int getCharisma() { return this->charisma; }

	weapon getWeapon() { return this->playerWeapon; }
	head getHead() { return this->playerHead; }
	chest getChest() { return this->playerChest; }
	legs getLegs() { return this->playerLegs; }
	feet getFeet() { return this->playerFeet; }

	/* SETTERS */
	void setCharacterName(string characterNameValue);

	void setLevel(int levelValue);
	void setHealth();

	void setStrength(int strengthValue);
	void setDexterity(int dexterityValue);
	void setConstitution(int constitutionValue);
	void setIntelligence(int intelligenceValue);
	void setWisdom(int wisdomValue);
	void setCharisma(int charismaValue);

	void setWeapon(string weaponName, int weaponDamage);
	void setHead(string headName, int headArmor);
	void setChest(string chestName, int chestArmor);
	void setLegs(string legsName, int legsArmor);
	void setFeet(string feetName, int feetArmor);

	/* VIRTUAL FUNCTIONS */
	virtual void createClass() {};
	
	/* OVERLOADED OPERATORS */
	friend ostream& operator<<(ostream& os, const Player& plyr);
};

#endif
