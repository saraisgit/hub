#include "../inc/agent.hpp"

namespace experis
{

Agent::Agent(CtorArgs a_args)
: m_id(a_args.m_id)
, m_type(a_args.m_type)
, m_floor(a_args.m_floor)
, m_room(a_args.m_room)
, m_hub(a_args.m_hub)
, m_log(a_args.m_log)
{
    // empty
}

const AgentId Agent::GetId() const
{
    return m_id;
}

const AgentType Agent::GetType() const
{
    return m_type;
}

const Floor Agent::GetFloor() const
{
    return m_floor;
}

const Room Agent::GetRoom() const
{
    return m_room;
}

const HubInterfaceForAgents* Agent::GetHub() const
{
    return m_hub;
}

const Log Agent::GetLog() const
{
    return m_log;
}


} // experis