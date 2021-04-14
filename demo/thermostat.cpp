#include "../demo/thermostat.hpp"


namespace demo
{

Thermostat::Thermostat(experis::CtorArgs a_args)
: Agent(a_args) 
{
    config(a_args.m_config);
}


void Thermostat::config(std::string a_config) 
{;}


void Thermostat::SendEventToHub(experis::SharedPtr< experis::Event > a_event) const
{
    const experis::HubInterfaceForAgents* hub = GetHub();
    hub->SendEventToHub(a_event);
}


experis::SharedPtr< experis::Event > Thermostat::generateEvent(experis::Timestamp a_timestamp, std::string a_temperature) const
{
    return experis::SharedPtr< experis::Event >( new experis::Event(a_timestamp, GetLog(), GetFloor(), GetRoom(), a_temperature));
}

extern "C"
Thermostat* CreateThermostat(experis::CtorArgs a_args)
{
    return new Thermostat(a_args);
}

} // demo