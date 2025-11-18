class Entity {
public: 
    virtual void attack() = 0;
    virtual void castSpell() = 0;
    virtual void applyDamage() = 0;

    int getHealth() { return health; }
    int getMana() { return mana; }
    int getDamage() { return damage; }
    int getDefense() { return defense; }
    void setHealth(int newHealth) { health = std::min(newHealth, maxHealth); health = std::max(newHealth, 0); }
    void setMana(int newMana) { mana = std::min(newMana, maxMana); mana = std::max(newMana, 0); }
    void setDamage(int newDamage) { damage = newDamage; }
    void setDefense(int newDefense) { defense = newDefense; }

private:
    int health{};
    int maxHealth{};
    int mana{};
    int maxMana{};
    int damage{};
    int defense{};
    int level{};
    //std::vector<> effects
};