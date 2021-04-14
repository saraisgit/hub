#include "light.hpp"
#include "../inc/hub_interface_for_agents.hpp"
#include <iostream>

namespace demo
{

Light::Light(experis::CtorArgs a_args)
: Agent(a_args) 
{
    experis::HubInterfaceForAgents* hub = const_cast<experis::HubInterfaceForAgents*>(GetHub());
    hub->Subscribe(GetId(), "light_control", "ALL", "ALL");
    hub->Subscribe(GetId(), "ALL", "ALL", "ALL");
}

void Light::SendEventToAgent(experis::SharedPtr<experis::Event> a_event) 
{
    std::cout << "I am " << GetId() << " and I just received an event of type " << a_event->m_type << std::endl;
    if (a_event->m_type == "light_control")
    {
        std::cout << "new light color: " << a_event->m_additionalInfo << std::endl;
    }
    else
    {
        std::cout << "why didn't I sign up to a more specific channel?\n";
    }
    
}

extern "C"
Light* CreateLight(experis::CtorArgs a_args)
{
    return new Light(a_args);
}

} // demo