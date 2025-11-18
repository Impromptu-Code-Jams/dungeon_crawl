struct position {
    int x;
    int y;
};

class Entity {

    // did the attack succeed
    virtual bool attack();
    // did the spell succeed
    virtual bool castSpell();
    virtual void applyDamage(int damage);
    virtual void move(position newPosition);

    int getHealth() {return health;}
    int getMana() {return mana;}
    int getdamage() {return damage;}
    int getDefense() {return defense;}
    int getLevel() {return level;}
    position getPosition() {return positon;}
    char getGlyph() {return glyph;}
    void setHealth(int newHealth) {health = newHealth;}
    void setMana(int newMana) {mana = newMana;}
    void setdamage(int newDamage) {damage = newDamage;}
    void setDefense(int newDefense) {defense = newDefense}
    void setLevel(int newLevel) {level = newLevel;}
    void setPosition(position newPosition) {positon = newPosition;}
    void setGlyph(char newGlyph) {glyph = newGlyph;}
    
    private:
        int health;
        int mana;
        int damage;
        int defense;
        int level;
        position positon;
        char glyph;
        //std::vector<> effects
};