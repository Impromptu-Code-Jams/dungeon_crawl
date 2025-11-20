#pragma once

#include <memory>
#include <vector>
#include "IRoom.h"
#include "RoomApi.h"

class DungeonEngine
{
    public:
        DungeonEngine();
        
        void addRoom(std::unique_ptr<IRoom> room);
        void start();

    private:
        void enterRoom(int roomIndex);

        void handleInput();
        void render();

        void getUserInput();
        void loop();

        bool running;
        bool quit;

        int currentRoomIndex;
        std::vector<std::unique_ptr<IRoom>> rooms;
        RoomApi roomApi;

        bool hasInput;
        char inputBuffer;
};

