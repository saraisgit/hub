#include "../inc/ctorArgs.hpp"

namespace experis
{

CtorArgs::CtorArgs(AgentId a_id, AgentType a_type, Floor a_floor, Room a_room, Log a_log, ConfigInfo a_config, CreateFuncName a_func, HubInterfaceForAgents* a_hub) 
: m_id(a_id)
, m_type(a_type)
, m_floor(a_floor)
, m_room(a_room)
, m_log(a_log)
, m_config(a_config)
, m_createFunc(a_func)
, m_hub(a_hub)
{
    // empty
}

CtorArgs::CtorArgs(AgentId a_id, AgentType a_type, Floor a_floor, Room a_room, Log a_log, ConfigInfo a_config) 
: m_id(a_id)
, m_type(a_type)
, m_floor(a_floor)
, m_room(a_room)
, m_log(a_log)
, m_config(a_config)
, m_createFunc("")
, m_hub(0)
{
    // empty
}

} // experis