#pragma once

#include <string>
#include <vector>
#include "RoomApi.h"

RoomApi::RoomApi()
{
}

void RoomApi::showMessage(std::string const & message)
{
    messages.push_back(message);
}

std::vector<std::string> RoomApi::getMessages()
{
    return messages;
}


