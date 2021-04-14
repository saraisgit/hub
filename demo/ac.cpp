#include "ac.hpp"
#include "../inc/hub_interface_for_agents.hpp"
#include <iostream>

namespace demo
{

AC::AC(experis::CtorArgs a_args)
: Agent(a_args) 
{
    experis::HubInterfaceForAgents* hub = const_cast<experis::HubInterfaceForAgents*>(GetHub());
    hub->Subscribe(GetId(), "climate_control", "6", "ALL");
}

void AC::SendEventToAgent(experis::SharedPtr<experis::Event> a_event) 
{
    std::cout << "I am " << GetId() << " and I just received an event of type " << a_event->m_type << std::endl;
    if (a_event->m_additionalInfo == "22")
    {
        std::cout << "22 degrees? That's so cold! Let's change the lighting to blue\n";
        experis::SharedPtr< experis::Event > event = generateLightingEvent(a_event);
        SendEventToHub(event);
    }
}

void AC::SendEventToHub(experis::SharedPtr< experis::Event > a_event) 
{
    const experis::HubInterfaceForAgents* hub = GetHub();
    hub->SendEventToHub(a_event);
}

experis::SharedPtr< experis::Event > AC::generateLightingEvent(experis::SharedPtr< experis::Event > a_incomingEvent) 
{
    return experis::SharedPtr<experis::Event>(new experis::Event(a_incomingEvent->m_timestamp, "light_control", a_incomingEvent->m_floor, a_incomingEvent->m_room, "BLUE"));
}

extern "C"
AC* CreateAC(experis::CtorArgs a_args)
{
    return new AC(a_args);
}

} // demo