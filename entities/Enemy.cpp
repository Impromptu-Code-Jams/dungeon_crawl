#include "Enemy.hpp"

Enemy::Enemy()
{
	// Set the Enemy attributes
	setHealth(100);
	setMana(100);
	setDamage(5);
	setDefense(5);
	setStatus(ALIVE);

	x = 2;
	y = 2;
	glyph = 'g';

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


void Enemy::useConsumable(int consumeIndex)
{
	if (consumeIndex < inventory.consumables.size())
	{
		applyEffect(inventory.consumables.at(consumeIndex).effect);
	}
}

void Enemy::updatePosition(int playerX, int playerY) {
	if (x > playerX) x--;
	else if (x < playerX) x++;
	else if (y > playerY) y--;
	else if (y < playerY) y++;
};