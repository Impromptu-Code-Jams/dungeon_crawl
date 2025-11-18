#pragma once

#include <memory>
#include <vector>
#include "Room.h"
#include "RoomApi.h"

class DungeonEngine
{
    public:
        DungeonEngine();
        
        void addRoom(std::unique_ptr<Room> room);
        void start();

    private:
        void enterRoom(int roomIndex);

        void handleInput();
        void render();

        void getInput();
        void loop();

        bool running;
        bool quit;

        int currentRoomIndex;
        std::vector<std::unique_ptr<Room>> rooms;
        RoomApi roomApi;

        bool hasInput;
        std::string inputBuffer;
};

