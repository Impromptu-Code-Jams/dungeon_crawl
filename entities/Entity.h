#pragma once
#include <optional>
#include <unordered_map>
#include "Effect.hpp"

enum Status { ALIVE, DEAD };

class Entity {
public:
    virtual std::optional<int> attack() = 0;
    virtual std::optional<int> castSpell() = 0;
    virtual Status applyDamage(int damageAmount) = 0;

    // Update loop for effects 
    void update()
    {
        // Update the effects
        for (std::vector<Effect>::iterator itr = effects.begin(); itr != effects.end();)
        {
            // Check if the turns for the effect are up
            if (itr->duration == 0)
            {
                itr = effects.erase(itr);
                continue;
            }
            applyEffect(*itr);
            itr++;
        }
    }

    virtual void applyEffect(Effect& effect)
    {
        effect.duration--; // Is being used 

        switch (effect.type) {
        case(Effect::FIRE): {
            setHealth(getHealth() - dynamic_cast<Fire&>(effect).damage);
            break;
        }
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
        }

        // If it's a multi-turn effect, add it
        if (effect.duration > 0)
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
        }
    }

    // Entity attribute headers 
    int getHealth() { return health; }
    int getMana() { return mana; } 
    bool getCanUseMana() { return canUseMana; } // changed by effects only
    int getDamage() { return damage; }
    int getDefense() { return defense; }
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

    // Scaling attribute
    int level{};

    std::vector<Effect > effects{};
}; 