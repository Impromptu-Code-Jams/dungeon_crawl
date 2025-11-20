#include "Player.hpp"

Player::Player()
{
	// Set the player attributes
	setHealth(100);
	setMana(100);
	setDamage(5);
	setDefense(5);
	setStatus(ALIVE);

	// Give the player a bad default weapon
	Weapon stick;
	stick.name = "stick";
	stick.damage = 2;
	addItem(static_cast<Item&>(stick));
	currentWeapon = stick;

	// Give the player a bad default shield
	Shield shield; 
	shield.name = "blocker";
	shield.blockPercent = 0.1; // 10% of damage gets blocked
	addItem(static_cast<Item&>(shield));
	currentShield = shield;
}

std::optional<int> Player::attack()
{
	std::optional<int> damageDealt; 

	// Check if the player has a weapon equipped
	if (currentWeapon.has_value() && !isBlocking() && canUseWeapon)
	{
		damageDealt = std::make_optional<int>(currentWeapon.value().damage);
	}
	// No weapon equipped - player base damage
	else
	{
		damageDealt = std::make_optional<int>(getDamage());
	}

	// TODO: apply any player-specific stats/buffs
	return damageDealt;
}

std::optional<int> Player::castSpell(int index)
{
	std::optional<int> spellDamage; 

	// The player can cast, the spell exists and there's enough mana for the action
	if (getCanUseMana() && 
		index < inventory.spells.size() && 
		getMana() - inventory.spells.at(index).manaCost >= 0)
	{
		spellDamage = std::make_optional<int>(inventory.spells.at(index).manaCost);
	}

	return spellDamage;
}

Status Player::applyDamage(int damageAmount)
{
	if (isBlocking() && canUseShield && currentShield.has_value())
	{
		damageAmount -= (damageAmount * currentShield.value().blockPercent);
	}

	setHealth(getHealth() - damageAmount);

	return getStatus();
}

void Player::addXp(int xpAdd)
{

}

void Player::changeWeapon(int weaponIndex)
{
	if (weaponIndex < inventory.weapons.size())
	{
		currentWeapon = inventory.weapons.at(weaponIndex);
	}
}

void Player::changeShield(int shieldIndex)
{
	if (shieldIndex < inventory.shields.size())
	{
		currentShield = inventory.shields.at(shieldIndex);
	}
}
