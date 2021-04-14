#pragma once

#include <string>
#include <cstddef>
#include "../inc/agent.hpp"
#include "../inc/event.hpp"
#include "../inc/commonTypedefs.hpp"

namespace demo
{

class AC : public experis::Agent
{
public:
    AC(experis::CtorArgs a_args);

    void Subscribe(experis::AgentId, experis::EventType, experis::Floor, experis::Room);
    virtual void SendEventToAgent(experis::SharedPtr<experis::Event> a_event);
    virtual void SendEventToHub(experis::SharedPtr< experis::Event > a_event);

//private:
    experis::SharedPtr< experis::Event > generateLightingEvent(experis::SharedPtr< experis::Event > a_incomingEvent);
    void config(std::string a_config);
    
};



} // demo