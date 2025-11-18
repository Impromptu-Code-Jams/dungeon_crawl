#include "Room.h"

Room::Room(const std::string &name)
: name{name}, x{8}, y{10}
{
}

std::string Room::getName() const
{
    return name;
}

int Room::getX() const
{
    return x;
}

int Room::getY() const
{
    return y;
}

std::vector<std::string> Room::render() const {
    std::vector<std::string> view = {x, std::string(y, '.')};
    for 
}
