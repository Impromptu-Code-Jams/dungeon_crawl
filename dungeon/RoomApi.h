#pragma once

#include <memory>
#include <vector>

class RoomApi
{
    public:
        RoomApi();
        void showMessage(std::string const & message);
        std::vector<std::string> getMessages();

    private:
        std::vector<std::string> messages;
};

