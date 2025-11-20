#include "Enemy.hpp"

Enemy::Enemy()
{
	glyph = 'g';
}

std::optional<int> Enemy::attack()
{
	return std::make_optional<int>(0);
}

std::optional<int> Enemy::castSpell()
{
	return std::make_optional<int>(0);
}

Status Enemy::applyDamage(int damageAmount)
{
	return DEAD;
}

Effect Enemy::getNextPlay()
{
	Effect effect; 

	// Check if the enemy should heal 
	if (((double)getHealth() / getMaxHealth()) < healPercent && 
		inventory.consumables.contains("Health Potion"))
	{
		
	}
	// Check if the enemy should increase mana
	else if (((double)getMana() / getMaxMana() < manaPercent) && 
		inventory.consumables.contains("Mana Potion"))
	{

	}
	else
	{
		// Check if the enemy should block 

		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0.0, 1.0);

		// The enemy should block 
		if (dis(gen) < blockChance)
		{

		}
		// See if the enemy can cast any spells 
		
	}

	return effect;
}