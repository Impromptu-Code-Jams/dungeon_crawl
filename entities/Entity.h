class Entity {
    virtual void attack();
    virtual void castSpell();
    virtual void applyDamage();

    int getHealth() {return health;}
    int getMana() {return mana;}
    int getdamage() {return damage;}
    int getDefense() {return defense;}
    void setHealth(int newHealth) {health = newHealth;}
    void setMana(int newMana) {mana = newMana;}
    void setdamage(int newDamage) {damage = newDamage;}
    void setDefense(int newDefense) {defense = newDefense}
    
    private:
        int health;
        int mana;
        int damage;
        int defense;
        int level;
        //std::vector<> effects
};