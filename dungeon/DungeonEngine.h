#pragma once

#include <memory>
#include <vector>
#include "IRoom.h"

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

        void getInput();
        void loop();

        bool running;
        bool quit;
        int currentRoomIndex;
        std::vector<std::unique_ptr<IRoom>> rooms;
        bool hasInput;
        std::string inputBuffer;
        std::vector<std::string> textLog;
};

