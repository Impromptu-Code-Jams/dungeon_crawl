#pragma once
#include <optional>
#include <unordered_map>
#include "Effect.hpp"

enum Status { ALIVE, DEAD };

class Entity {
public:
    virtual std::optional<int> attack() = 0;
    virtual std::optional<int> castSpell(int index) = 0;
    virtual Status applyDamage(const int damageAmount) = 0;
    
    int x;
    int y;
    char glyph;

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

    void applyEffect(Effect& effect)
    {
        effect.duration--; // Is being used 

        switch (effect.type) 
        {
        case (Effect::STRENGTH_EFFECT): {
            tempDamageMod += dynamic_cast<StrengthEffect&>(effect).modifierValue;
            break;
        }
        case (Effect::DEFENSE_EFFECT): {
            tempDefenseMod += dynamic_cast<DefenseEffect&>(effect).modifierValue;
            break;
        }
        case (Effect::HEALTH_EFFECT): {
            setHealth(getHealth() + dynamic_cast<HealthEffect&>(effect).modifierValue);
            break;
        }
        case (Effect::MANA_EFFECT): {
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
    
    void removeEffect(Effect& effect)
    {
        switch (effect.type) {
        case (Effect::STRENGTH_EFFECT): {
            tempDamageMod -= dynamic_cast<StrengthEffect&>(effect).modifierValue;
            break;
        }
        case (Effect::DEFENSE_EFFECT): {
            tempDefenseMod -= dynamic_cast<DefenseEffect&>(effect).modifierValue;
            break;
        }
        case (Effect::MANA_EFFECT): {
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

    std::vector<Effect> effects{};
};