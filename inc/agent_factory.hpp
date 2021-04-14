#pragma once

#include <map>
#include <string>
#include <algorithm>
#include "../../inc/common.hpp"
#include "../../inc/commonExc.hpp"
#include "commonTypedefs.hpp"
#include "hub_interface_for_agents.hpp"
#include "agent_interface_for_hub.hpp"
#include "agent.hpp"
#include "../../inc/ctorMap.hpp"

namespace experis
{

typedef Agent* (*AgentCtorCaller)(CtorArgs);
typedef std::vector< std::pair< FilePath, FuncName > > ArgsAndFilesContainer;

class AgentFactory : public Uncopyable
{
public:
    explicit AgentFactory(ArgsAndFilesContainer& a_sosAndFuncNames);
    AgentInterfaceForHub* GenerateAgent(CtorArgs a_args) const;
    
private:
    CtorMap<Agent, CtorArgs> m_ctorMap;
};



DEFINE_EXCEPTION(AgentTypeDoesNotExist, "ERROR: this Agent type does not exist")


} // experis