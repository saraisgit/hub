#pragma once

#include <string>
#include <vector>
#include <map>
#include "hub_interface_for_agents.hpp"
#include "agent_interface_for_hub.hpp"
#include "../../inc/thread_pool.hpp"
#include "subscriptionService.hpp"

namespace experis
{

class Hub : public HubInterfaceForAgents
{
public:
    typedef std::map<AgentId, AgentInterfaceForHub*> AgentRegistry;

    explicit Hub(std::string a_filePath, size_t a_numIncomingEventHandlers, size_t a_numOutgoingEventHandlers);
    ~Hub();

    void Run();
    virtual void SendEventToHub(SharedPtr<Event> a_event) const;
    virtual void Subscribe(AgentId, EventType, Floor, Room = "ALL");

private:
    AgentRegistry initialize(std::string a_filepath);
    void publishEvent(SharedPtr<Event> a_event) const;

private:
    mutable ThreadPool m_incomingEvents;
    mutable ThreadPool m_outgoingEvents;
    SubscriptionService m_subscriptionService;
    AgentRegistry m_agents;

    friend class IncomingEventHandler;
};




} // experis