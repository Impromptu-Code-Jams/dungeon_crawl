#include "Entity.h"
#include <string>
#include <memory>

enum itemType {
    Weapon,
    Armor,
    Consumable
    //other types
};

struct item {
    std::string name;
    itemType value;
    //other stats
};

struct loot {
    int xp;
    int gold;
    //items
    item drop;
};

class Monster : public Entity {

    bool attack() override;
    bool castSpell() override;
    void applyDamage(int damage) override;
    void move(position) override;

    void onDeath();
    std::unique_ptr<loot> dropLoot();
    position nextMove();

    private:
        std::unique_ptr<loot> lootDrop;
    //LootDrop
};