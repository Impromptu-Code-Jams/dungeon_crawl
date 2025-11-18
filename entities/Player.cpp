#include "Player.hpp"

Player::Player()
{
	setHealth(100);
	setMana(100);

	setDamage(5);
	setDefense(5);

	Weapon stick;
	stick.damage = 5;
	addItem(static_cast<Item&>(stick));
}

void Player::attack()
{

}

int Player::castSpell(int index)
{

	return 0;
}

void Player::applyDamage()
{

}

void Player::addXp(int xpAdd)
{

}

void Player::addItem(Item& item)
{
	switch (item.type)
	{
	case (CONSUMABLE): {
		Consumable& consumable = dynamic_cast<Consumable&>(item);
		inventory.consumables.emplace_back(consumable);
		break;
	}
	case (WEAPON): {
		Weapon& weapon = dynamic_cast<Weapon&>(item);
		inventory.weapons.emplace_back(weapon);
		break;
	}
	case (SPELL): {
		Spell& spell = dynamic_cast<Spell&>(item);
		inventory.spells.emplace_back(spell);
		break;
	}
	}
}

void Player::removeItem(int itmRmv)
{

}

void Player::changeWeapon(int weaponIndex)
{

}