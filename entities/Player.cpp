#include "Player.hpp"

Player::Player()
{
	setHealth(100);
	setMana(100);

	setDamage(5);
	setDefense(5);

	Item stick;
	addItem(stick);
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

void Player::addItem(Item item)
{
	switch (item.type)
	{
	case (CONSUMABLE): {
		inventory.consumables.emplace_back(item);
		break;
	}
	case (WEAPON): {
		inventory.weapons.emplace_back(item);
		break;
	}
	case (SPELL): {
		inventory.spells.emplace_back(item);
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