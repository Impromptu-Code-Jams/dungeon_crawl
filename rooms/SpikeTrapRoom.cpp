#include "SpikeTrapRoom.h"

SpikeTrapRoom::SpikeTrapRoom()
{
    tileMap = {
        "################",
        "#..............#",
        "#..............#",
        "#..............#",
        "################"
    };
}

std::string const SpikeTrapRoom::name() const
{
    return "SpikeTrapRoom";
}

std::vector<std::string> SpikeTrapRoom::getTileMap() const
{
    return tileMap;
}
