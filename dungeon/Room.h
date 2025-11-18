#pragma once
#include <string>
#include <vector>

#include <entites/Entity.h>

class Room
{
    public:
        Room(const std::string& name);

        std::string getName() const;
        int getX() const;
        int getY() const;

        std::vector<std::string> render() const;
        

    private:
        std::string name;
        int x;
        int y;

        struct Point
        {
            int x;
            int y;
        };
        std::map<Point, Entity>
};

