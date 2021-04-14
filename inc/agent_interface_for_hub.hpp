#pragma once

#include "event.hpp"
#include "../inc/hub_interface_for_agents.hpp"
#include "ctorArgs.hpp"


namespace experis
{

class AgentInterfaceForHub
{
public:
    virtual void SendEventToAgent(SharedPtr<Event> a_event) = 0;
};


} // experis