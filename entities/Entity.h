#pragma once
#include <optional>
#include <ranges>
#include <unordered_map>
#include "Effect.hpp"
#include "Item.hpp"

enum Status { ALIVE, DEAD };

struct Inventory
{
    std::unordered_map<std::string, Consumable> consumables;
    std::unordered_map<std::string, Weapon> weapons;
    std::unordered_map<std::string, Shield> shields;
    std::unordered_map<std::string, Spell> spells;
};

class Entity {
public:
    virtual std::optional<int> attack() = 0;
    virtual std::optional<int> castSpell() = 0;
    virtual Status applyDamage(int damageAmount) = 0;
    
    void blockNextAttack() { block = true; }

    // Use a consumable from the inventory
    void useConsumable(std::string consumeName)
    {
        if (inventory.consumables.size())
        {
            applyEffect(inventory.consumables.at(consumeName).effect, true);
            inventory.consumables.erase(consumeName);
        }
    }

    // Add an item to the inventory
    void addItem(Item& item)
    {
        switch (item.type)
        {
        case (Item::CONSUMABLE): {
            Consumable& consumable = dynamic_cast<Consumable&>(item);
            inventory.consumables.emplace(consumable.name, consumable);
            break;
        }
        case (Item::WEAPON): {
            Weapon& weapon = dynamic_cast<Weapon&>(item);
            inventory.weapons.emplace(weapon.name, weapon);
            break;
        }
        case (Item::SPELL): {
            Spell& spell = dynamic_cast<Spell&>(item);
            inventory.spells.emplace(spell.name, spell);
            break;
        }
        case (Item::SHIELD): {
            Shield& shield = dynamic_cast<Shield&>(item);
            inventory.shields.emplace(shield.name, shield);
            break;
        }
        }
    }

    // Update loop for effects 
    void update()
    {
        // Update the effects
        for (std::vector<Effect>::iterator itr = effects.begin(); itr != effects.end();)
        {
            // Check if the turns for the effect are up
            if (itr->duration == 0)
            {
                removeEffect(*itr);
                continue;
            }
            applyEffect(*itr, true);
            itr++;
        }
    }

    virtual void applyEffect(Effect& effect, bool updatingEffect)
    {
        effect.duration--; // Is being used 

        switch (effect.type) {
        case (Effect::STRENGTH_MOD): {
            tempDamageMod += dynamic_cast<StrengthMod&>(effect).mod;
            break;
        }
        case (Effect::DEFENSE_MOD): {
            tempDefenseMod += dynamic_cast<DefenseMod&>(effect).mod;
            break;
        }
        case (Effect::HEALTH_MOD): {
            setHealth(getHealth() + dynamic_cast<HealthMod&>(effect).mod);
            break;
        }
        case (Effect::BLOCK_MAGIC): {
            canUseMana = false;
            break;
        }
        case (Effect::DISARM): {
            canUseShield = false; 

        }
        }

        // If it's a multi-turn effect, add it
        if (effect.duration > 0 && !updatingEffect)
        {
            effects.emplace_back(effect);
        }
    }
    
    virtual void removeEffect(Effect& effect)
    {
        switch (effect.type) {
        case (Effect::STRENGTH_MOD): {
            tempDamageMod -= dynamic_cast<StrengthMod&>(effect).mod;
            break;
        }
        case (Effect::DEFENSE_MOD): {
            tempDefenseMod -= dynamic_cast<DefenseMod&>(effect).mod;
            break;
        }
        case (Effect::BLOCK_MAGIC): {
            canUseMana = true;
            break;
        }
        case (Effect::DISARM):
        {
            canUseWeapon = true;
            canUseShield = true;
        }
        }
    }

    int x{};
    int y{};
    char glyph{};

    // Entity attribute headers 
    int getHealth() { return health; }
    int getMaxHealth() { return maxHealth; }
    int getMana() { return mana; } 
    int getMaxMana() { return maxMana; }
    bool getCanUseMana() { return canUseMana; } // changed by effects only
    int getDamage() { return damage; }
    int getDefense() { return defense; }
    bool isBlocking() { return block; }
    Status getStatus() { return status; }

    // Entity attribute setters
    void setHealth(int newHealth) {
        health = std::min(newHealth, maxHealth);
        health = std::max(newHealth, 0);
        if (health == 0) { status = DEAD; }
    }
    void setMana(int newMana) { mana = std::min(newMana, maxMana); mana = std::max(newMana, 0); }
    void setDamage(int newDamage) { damage = newDamage; }
    void setDefense(int newDefense) { defense = newDefense; }
    void setStatus(Status st) { status = st; }

    // Inventory accessors
    const std::unordered_map<std::string, Spell>& getSpells() const { return inventory.spells; }
    const std::unordered_map<std::string, Weapon>& getWeapons() const { return inventory.weapons; }
    const std::unordered_map<std::string, Consumable> & getConsumables() const { return inventory.consumables; }
    const std::unordered_map<std::string, Shield>& getShields() const { return inventory.shields; }

protected:
    // Inventory management
    Inventory inventory;

    std::optional<Weapon> currentWeapon;
    bool canUseWeapon{ true };
    std::optional<Shield> currentShield;
    bool canUseShield{ true };

private:
    // Health trackers 
    Status status{};
    int health{};
    int maxHealth{};

    // Mana attributes 
    int mana{};
    int maxMana{};
    bool canUseMana{true};

    // Fighting attributes
    int damage{};
    int tempDamageMod{};
    int defense{};
    int tempDefenseMod{};
    bool block{};

    // Scaling attribute
    int level{};

    // Effects being applied to the player 
    std::vector<Effect > effects{};

}; 