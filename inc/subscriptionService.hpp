#pragma once

#include "event.hpp"
#include "agent_interface_for_hub.hpp"
#include "thread_pool.hpp"
//#include "hub.hpp"
#include <map>
#include <vector>
#include <list>

namespace experis
{

typedef std::map< AgentId, std::list< Channel > > SubscriberLists;

class SubscriptionService
{
public:
    SubscriptionService(ThreadPool& a_pool, std::map<AgentId, AgentInterfaceForHub*>& a_agents);

    void AddSubscription(AgentId a_agent, Channel a_channel);
    void PublishEvent(SharedPtr<Event> a_event) const;

private:
    bool assessSingleleSubscriber(AgentId a_sub, SharedPtr<Event> a_event) const;

private:
    ThreadPool& m_pool;
    SubscriberLists m_idToChannels;
    std::map< AgentId, AgentInterfaceForHub* >& m_idToPtr;

    friend class Dispatcher;
    friend class OutgoingEventHandler;
};

DEFINE_EXCEPTION(UnregisterdAgent, "ERROR: attempted to add a subscription to an unregistered Agent")






} // experis