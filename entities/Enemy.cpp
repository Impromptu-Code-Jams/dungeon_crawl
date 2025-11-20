#include "Enemy.hpp"

Enemy::Enemy()
{
	// Set the Enemy attributes
	setHealth(100);
	setMana(100);
	setDamage(5);
	setDefense(5);
	setStatus(ALIVE);

	// Give the Enemy a bad default weapon
	Weapon stick;
	stick.name = "stick";
	stick.damage = 2;
	addItem(static_cast<Item&>(stick));
	currentWeapon = stick;

	// Give the Enemy a bad default shield
	Shield shield; 
	shield.name = "blocker";
	shield.blockPercent = 0.1; // 10% of damage gets blocked
	addItem(static_cast<Item&>(shield));
	currentShield = shield;
}

std::optional<int> Enemy::attack()
{
	std::optional<int> damageDealt; 

	// Check if the Enemy has a weapon equipped
	if (currentWeapon.has_value() && !block && canUseWeapon)
	{
		damageDealt = std::make_optional<int>(currentWeapon.value().damage);
	}
	// No weapon equipped - Enemy base damage
	else
	{
		damageDealt = std::make_optional<int>(getDamage());
	}

	// TODO: apply any Enemy-specific stats/buffs
	return damageDealt;
}

std::optional<int> Enemy::castSpell(int index)
{
	std::optional<int> spellDamage; 

	// The Enemy can cast, the spell exists and there's enough mana for the action
	if (getCanUseMana() && 
		index < inventory.spells.size() && 
		getMana() - inventory.spells.at(index).manaCost >= 0)
	{
		spellDamage = std::make_optional<int>(inventory.spells.at(index).manaCost);
	}

	return spellDamage;
}

Status Enemy::applyDamage(int damageAmount)
{
	if (block && canUseShield && currentShield.has_value())
	{
		damageAmount -= (damageAmount * currentShield.value().blockPercent);
	}

	setHealth(getHealth() - damageAmount);

	return getStatus();
}

void Enemy::addXp(int xpAdd)
{

}

void Enemy::addItem(Item& item)
{
	switch (item.type)
	{
	case (Item::CONSUMABLE): {
		Consumable& consumable = dynamic_cast<Consumable&>(item);
		inventory.consumables.emplace_back(consumable);
		break;
	}
	case (Item::WEAPON): {
		Weapon& weapon = dynamic_cast<Weapon&>(item);
		inventory.weapons.emplace_back(weapon);
		break;
	}
	case (Item::SPELL): {
		Spell& spell = dynamic_cast<Spell&>(item);
		inventory.spells.emplace_back(spell);
		break;
	}
	case (Item::SHIELD): {
		Shield& shield = dynamic_cast<Shield&>(item);
		inventory.shields.emplace_back(shield);
		break;
	}
	}
}

void Enemy::useConsumable(int consumeIndex)
{
	if (consumeIndex < inventory.consumables.size())
	{
		applyEffect(inventory.consumables.at(consumeIndex).effect);
	}
}

void Enemy::changeWeapon(int weaponIndex)
{
	if (weaponIndex < inventory.weapons.size())
	{
		currentWeapon = inventory.weapons.at(weaponIndex);
	}
}

void Enemy::changeShield(int shieldIndex)
{
	if (shieldIndex < inventory.shields.size())
	{
		currentShield = inventory.shields.at(shieldIndex);
	}
}

void Enemy::applyEffect(Effect& effect)
{
	Entity::applyEffect(effect); 

	if (effect.type == Effect::DISARM)
	{
		canUseWeapon = false;
		canUseShield = true;
	}
}

void Enemy::removeEffect(Effect& effect)
{
	Entity::removeEffect(effect); 

	if (effect.type == Effect::DISARM)
	{
		canUseWeapon = true; 
		canUseShield = true;
	}
}