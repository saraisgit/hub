#pragma once

#include "event.hpp"
#include "commonTypedefs.hpp"
#include "shared_ptr.hpp"

namespace experis
{

class HubInterfaceForAgents
{
public:
    virtual void SendEventToHub(SharedPtr<Event>) const = 0;
    virtual void Subscribe(AgentId, EventType, Floor, Room) = 0;
};



} // experis