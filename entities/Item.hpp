#include <string>

enum Type { WEAPON, CONSUMABLE, SPELL };

class Item
{
public:
	std::string name{};
	Type type{};
};

