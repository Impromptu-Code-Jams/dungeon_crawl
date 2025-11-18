#pragma once
#include <string>
#include <vector>

class IRoom
{
    public:
        virtual ~IRoom() {}
        virtual std::string const name() const = 0;
        virtual std::vector<std::string> getTileMap() const = 0;
//        virtual void onEnter(Player& player, Dungeon& dungeon) = 0;
//        virtual void onPlayerStep(Player& player, Dungeon& dungeon) = 0;
//        virtual void onTick(Player& player, Dungeon& dungeon) = 0;
//        virtual bool isComplete() const = 0;        
};

