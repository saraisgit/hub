#pragma once

#include <cstddef>
#include <string>
#include "hub_interface_for_agents.hpp"
#include "agent_interface_for_hub.hpp"
#include "commonTypedefs.hpp"

namespace experis
{

class Agent : public AgentInterfaceForHub
{
public:
    Agent(CtorArgs a_args);
protected:
    virtual void SendEventToAgent(SharedPtr<Event>) {}
    
    void Subscribe(AgentId, EventType, Floor, Room) {}
    void SendEventToHub(Event*);

    const AgentId GetId() const;
    const AgentType GetType() const;
    const Floor GetFloor() const;
    const Room GetRoom() const;
    const HubInterfaceForAgents* GetHub() const;
    const Log GetLog() const;

private:
    AgentId m_id;
    AgentType m_type;
    Floor m_floor;
    Room m_room;
    HubInterfaceForAgents* m_hub;
    Log m_log;
};



} // experis