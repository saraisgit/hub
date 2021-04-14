#include "../inc/initializer.hpp"

namespace experis
{

Initializer::Initializer(HubInterfaceForAgents& a_hub, FilePath a_path) 
: m_agents(new AgentContainer) // will be deleted in Hub's dtor
, m_parser(a_path)
, m_hub(a_hub)
{;}

Initializer::AgentContainer Initializer::GenerateAgents() 
{
    std::vector<CtorArgs> argVect;
    while (true)
    {
        try
        {
            CtorArgs args = m_parser.Parse();
            args.m_createFunc = "Create" + args.m_type;
            args.m_hub = &m_hub;

            argVect.push_back(args);
        }
        catch(NoMoreAgents&)
        {
            break;
        }
    }

    ArgsAndFilesContainer container;
    for (size_t i = 0; i < argVect.size(); ++i)
    {
        std::string so = "./lib" + argVect[i].m_type;
        so += ".so";
        container.push_back(std::make_pair(so, argVect[i].m_createFunc));
    }
    std::map<AgentId, AgentInterfaceForHub*> locMap;
    AgentFactory factory(container);
    for (size_t i = 0; i < argVect.size(); ++i)
    {
        locMap.insert(std::make_pair(argVect[i].m_id, factory.GenerateAgent(argVect[i])));
    }

    return locMap;
}

} // experis