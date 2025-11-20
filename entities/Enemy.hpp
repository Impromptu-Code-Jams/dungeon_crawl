#include "Entity.h"

class Enemy : public Entity
{
public: 
	Enemy(); 

    // Inherited functions
    virtual std::optional<int> attack();
    virtual std::optional<int> castSpell();
    virtual Status applyDamage(int damageAmount);


};