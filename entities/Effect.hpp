#pragma once 
#include <string>

struct Effect
{
public: 
	enum Type {STRENGTH_EFFECT, DEFENSE_EFFECT, HEALTH_EFFECT, MANA_EFFECT};
	virtual ~Effect() = default;
	int duration{};
	Type type{};
};

struct StrengthEffect : public Effect
{
public:
	StrengthEffect(int modValue) { modifierValue = modValue; }
	Type type{ STRENGTH_EFFECT };
	int modifierValue{}; 
};

struct DefenseEffect : public Effect
{
public: 
	DefenseEffect(int modValue) { modifierValue = modValue;	}
	Type type{ DEFENSE_EFFECT };
	int modifierValue{};
};

struct HealthEffect : public Effect
{
public: 
	HealthEffect(int modValue) { modifierValue = modValue; }
	Type type{ HEALTH_EFFECT };
	int modifierValue{};
};

struct ManaEffect : public Effect
{
	ManaEffect(int modValue) { modifierValue = modValue; }
	Type type{ MANA_EFFECT };
	int modifierValue{};
};