#pragma once 
#include <string>

struct Effect
{
public: 
	enum Type { FIRE, STRENGTH_MOD, DEFENSE_MOD, HEALTH_MOD, BLOCK_MAGIC, DISARM };
	virtual ~Effect() = default;;

	std::string name{};
	int duration{};
	Type type{};
};

struct Fire : public Effect
{
public: 
	Fire() { type = FIRE; }
	int damage{}; 
};

struct StrengthMod : public Effect
{
public:
	StrengthMod() { type = STRENGTH_MOD; }
	int mod{}; 
};

struct DefenseMod : public Effect
{
public: 
	DefenseMod() { type = DEFENSE_MOD; }
	int mod{};
};

struct HealthMod : public Effect
{
public: 
	HealthMod() { type = HEALTH_MOD; }
	int mod{};
};

struct BlockMagic : public Effect
{
public: 
	BlockMagic() { type = BLOCK_MAGIC; }
};

struct Disarm : public Effect
{
public: 
	Disarm() { type = DISARM; }
};