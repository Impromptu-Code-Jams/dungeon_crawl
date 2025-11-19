#pragma once
#include <optional>

enum Status { ALIVE, DEAD };

class Entity {
public:
    virtual std::optional<int> attack() = 0;
    virtual std::optional<int> castSpell() = 0;
    virtual Status applyDamage(int damageAmount) = 0;

    // Entity attribute headers 
    int getHealth() { return health; }
    int getMana() { return mana; }
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

    // Fighting attributes
    int damage{};
    int defense{};

    // Scaling attribute
    int level{};

    //std::vector<> effects
};