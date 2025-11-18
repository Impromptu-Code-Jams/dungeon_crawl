#include "Monster.h"

bool Monster::attack() 
{

}

bool Monster::castSpell() 
{

}

void Monster::applyDamage(int damage) 
{

}

void Monster::move(position newPosition) 
{   

}

void Monster::onDeath() 
{   

}

std::unique_ptr<loot> Monster::dropLoot() 
{   
    return std::move(lootDrop);
}

position Monster::nextMove() {
    //todo: implement simple AI for monster movement
    return position{0, 0};
}
