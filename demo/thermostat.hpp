#pragma once

#include <string>
#include <cstddef>
#include "../inc/agent.hpp"
#include "../inc/event.hpp"

namespace demo
{

class Thermostat : public experis::Agent
{
public:
    Thermostat(experis::CtorArgs a_args);
    virtual void SendEventToHub(experis::SharedPtr< experis::Event > a_event) const;

//private:
    void config(std::string a_config);
    experis::SharedPtr< experis::Event > generateEvent(experis::Timestamp a_timestamp, std::string a_temperature) const;
};



} // demo