#pragma once

#include "commonTypedefs.hpp"

namespace experis
{

class HubInterfaceForAgents;

struct CtorArgs
{
    CtorArgs(AgentId a_id, AgentType a_type, Floor a_floor, Room a_room, Log a_log, ConfigInfo a_config, CreateFuncName a_func, HubInterfaceForAgents* a_hub);
    CtorArgs(AgentId a_id, AgentType a_type, Floor a_floor, Room a_room, Log a_log, ConfigInfo a_config);
    AgentId m_id;
    AgentType m_type;
    Floor m_floor;
    Room m_room;
    Log m_log;
    ConfigInfo m_config;
    CreateFuncName m_createFunc;
    HubInterfaceForAgents* m_hub;
};


} // experis