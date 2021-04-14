#pragma once

#include <vector>
#include "../../inc/common.hpp"
#include "commonTypedefs.hpp"
#include "parser.hpp"
#include "ctorArgs.hpp"
#include "agent_factory.hpp"
#include "agent_interface_for_hub.hpp"
#include "hub_interface_for_agents.hpp"

namespace experis
{

class Initializer : public Uncopyable
{
typedef std::map<AgentId, AgentInterfaceForHub*> AgentContainer;
public:
    explicit Initializer(HubInterfaceForAgents& a_hub, FilePath a_path);

public:
    AgentContainer GenerateAgents();

private:
    AgentContainer* m_agents;
    Parser m_parser;
    HubInterfaceForAgents& m_hub;
};



} // experis