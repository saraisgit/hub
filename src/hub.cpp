#include "../inc/hub.hpp"
#include "../../inc/shared_ptr.hpp"
#include "initializer.hpp"

namespace experis
{

Hub::Hub(std::string a_filePath, size_t a_numIncomingEventHandlers, size_t a_numOutgoingEventHandlers) 
: m_incomingEvents(a_numIncomingEventHandlers)
, m_outgoingEvents(a_numOutgoingEventHandlers)
, m_subscriptionService(m_outgoingEvents, m_agents)
, m_agents(initialize(a_filePath))
{;}

Hub::~Hub() 
{
    //delete m_agents; // was created in initializer
}

class IncomingEventHandler : public TaskFuncObjBase
{
public:
    IncomingEventHandler(SharedPtr<Event> a_event, const Hub& a_hub);
    void operator()();
private:
    const Hub& m_hub;
    SharedPtr<Event> m_event;
};

IncomingEventHandler::IncomingEventHandler(SharedPtr<Event> a_event, const Hub& a_hub) 
: m_hub(a_hub)
, m_event(a_event)
{;}

void IncomingEventHandler::operator()()
{
    m_hub.publishEvent(m_event);
}

class OutgoingEventHandler : public TaskFuncObjBase
{
public:
    OutgoingEventHandler(const SubscriptionService& a_manager, SharedPtr<Event> a_event) : m_manager(a_manager), m_event(a_event) {}
    void operator()();

private:
    const SubscriptionService& m_manager;
    SharedPtr<Event> m_event;
};

void OutgoingEventHandler::operator()() 
{
    m_manager.PublishEvent(m_event);
}

Hub::AgentRegistry Hub::initialize(std::string a_filepath) 
{
    Initializer initializer(*this, a_filepath);
    return initializer.GenerateAgents();
}

void Hub::SendEventToHub(SharedPtr<Event> a_event) const
{
    SharedPtr<OutgoingEventHandler> handler(new OutgoingEventHandler(m_subscriptionService, a_event));
    m_incomingEvents.Submit(handler);
}

void Hub::Subscribe(AgentId a_id, EventType a_type, Floor a_floor, Room a_room) 
{
    Channel channel = a_type + " " + a_floor + " " + a_room;
    std::map<AgentId, AgentInterfaceForHub*> ::iterator it;
    while (true)
    {
        try
        {
            it = m_agents.find(a_id);
            break;
        }
        catch(const std::exception& e)
        {;}
    }
    
    // if (m_agents.end() == it)
    // {
    //     throw UnregisterdAgent();
    // }
    m_subscriptionService.AddSubscription(a_id, channel);
}

void Hub::publishEvent(SharedPtr<Event> a_event) const
{
    m_subscriptionService.PublishEvent(a_event);
}

void Hub::Run() 
{
    while(true)
    {
        sleep(unsigned(~0));
    }
}

} // experis