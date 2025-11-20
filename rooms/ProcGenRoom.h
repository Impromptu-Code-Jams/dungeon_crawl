#include "IRoom.h"

class ProcGenRoom : public IRoom
{
public:
    ProcGenRoom();

    std::string name() const;
    std::vector<std::string> getTileMap() const;
    void onEnter(RoomApi& api);

private:
    int xMax{};
	int yMax{};
	void generateTileMap(int x, int y);
    std::vector<std::string> tileMap;
};

