#include "../inc/subscriptionService.hpp"
#include <algorithm>
#include <iostream>
#include <cassert>

namespace experis
{

class AddAgentToMap
{
public:
    AddAgentToMap(SubscriberLists& a_map) : m_map(a_map) {}
    void operator()(std::pair<AgentId, AgentInterfaceForHub*> a_agent);

private:
    SubscriberLists& m_map;
};

void AddAgentToMap::operator()(std::pair<AgentId, AgentInterfaceForHub*> a_agent) 
{
    m_map.insert(std::make_pair(a_agent.first, *(new std::list<Channel>)));
}

class Dispatcher
{
public:
    Dispatcher(const SubscriptionService& a_manager, SharedPtr<Event> a_event) : m_manager(a_manager), m_event(a_event) {;}
    void operator()(std::pair< AgentId, std::list< Channel > > a_agentAndChannels);

private:
    const SubscriptionService& m_manager;
    SharedPtr<Event> m_event;
};

SubscriptionService::SubscriptionService(ThreadPool& a_pool, std::map<AgentId, AgentInterfaceForHub*>& a_agents) 
: m_pool(a_pool)
, m_idToPtr(a_agents)
{;}

void SubscriptionService::AddSubscription(AgentId a_agent, Channel a_channel) 
{
    SubscriberLists::iterator it = m_idToChannels.find(a_agent);
    if (m_idToChannels.end() == it)
    {
        m_idToChannels.insert(std::make_pair(a_agent, *(new std::list<Channel>)));
        it = m_idToChannels.find(a_agent);
    }
    it->second.push_back(a_channel);
}

void SubscriptionService::PublishEvent(SharedPtr<Event> a_event) const
{
    Dispatcher dispatcher(*this, a_event);
    std::for_each(m_idToChannels.begin(), m_idToChannels.end(), dispatcher);
}

void Dispatcher::operator()(std::pair< AgentId, std::list< Channel > > a_agentAndChannels) 
{
    AgentId subscriber = a_agentAndChannels.first;
    if (m_manager.assessSingleleSubscriber(subscriber, m_event))
    {
        std::map<AgentId, AgentInterfaceForHub*>::iterator it = m_manager.m_idToPtr.find(subscriber);
        assert(it != m_manager.m_idToPtr.end());
        AgentInterfaceForHub* agent = it->second;
        agent->SendEventToAgent(m_event);
    }
}

bool SubscriptionService::assessSingleleSubscriber(AgentId a_sub, SharedPtr<Event> a_event) const
{
    Channel all = "ALL ALL ALL";
    Channel byType = a_event->m_type + " ALL + ALL";
    Channel byFloor = a_event->m_type + " " + a_event->m_floor + " ALL";
    Channel byRoom = a_event->m_type + " " + a_event->m_floor + " " + a_event->m_room;

    std::vector<Channel> vect;
    vect.push_back(all);
    vect.push_back(byType);
    vect.push_back(byFloor);
    vect.push_back(byRoom);

    std::map<AgentId, std::list<Channel> >::const_iterator it = m_idToChannels.find(a_sub);
    if (it == m_idToChannels.end())
    {
        throw UnregisterdAgent();
    }
    std::list< Channel > subscriptions = it->second;

    std::list<Channel>::iterator it2;
    for (size_t i = 0; i < vect.size(); ++i)
    {
        it2 = std::find(subscriptions.begin(), subscriptions.end(), vect[i]);
        if (it2 != subscriptions.end())
        {
            return true;
        }
    }
    return false;
}


}