#include <memory>
#include "DungeonEngine.h"
#include "SpikeTrapRoom.h"
#include "ProcGenRoom.h"

int main(int argc, char** argv)
{
    DungeonEngine engine;

    // Add rooms.
    engine.addRoom(std::make_unique<ProcGenRoom>());

    // Start the game.
    engine.start();

    return 0;
}

