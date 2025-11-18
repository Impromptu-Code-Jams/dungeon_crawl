#include "IRoom.h"

class SpikeTrapRoom : public IRoom
{
    public:
        SpikeTrapRoom();

        std::string const name() const;
        std::vector<std::string> getTileMap() const;

    private:
        std::vector<std::string> tileMap;
};

