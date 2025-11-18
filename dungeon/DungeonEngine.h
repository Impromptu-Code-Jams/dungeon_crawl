#pragma once

#include <memory>
#include <vector>
#include "IRoom.h"
#include "RoomApi.h"
#include "CombatManager.h"

class DungeonEngine
{
    public:
        DungeonEngine();
        
        void addRoom(std::unique_ptr<IRoom> room);
        void start();

    private:
        void enterRoom(int roomIndex);

        void showMessage(std::string const& message);
        std::vector<std::string> getMessages();

        void handleInput();
        void render();

        void getInput();
        void loop();

        bool running;
        bool quit;

        int currentRoomIndex;
        std::vector<std::unique_ptr<IRoom>> rooms;
        std::vector<std::string> messages;
        RoomApi roomApi;

        bool hasInput;
        std::string inputBuffer;
};

