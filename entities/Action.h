#include "Effect.hpp"
#include <string>
#include <optional>
class Action
{
public:
	enum Target {SELF, OTHER};
protected:
	Target target{};
	Effect effect{};
};