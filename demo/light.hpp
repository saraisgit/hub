#pragma once

#include <string>
#include <cstddef>
#include "../inc/agent.hpp"
#include "../inc/event.hpp"
#include "../inc/commonTypedefs.hpp"

namespace demo
{

class Light : public experis::Agent
{
public:
    Light(experis::CtorArgs a_args);

    void Subscribe(experis::AgentId, experis::EventType, experis::Floor, experis::Room);
    virtual void SendEventToAgent(experis::SharedPtr<experis::Event> a_event);

//private:
    void config(std::string a_config);
    
};



} // demo