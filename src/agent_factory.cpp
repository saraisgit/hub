#include "../inc/agent_factory.hpp"

namespace experis
{

AgentFactory::AgentFactory(ArgsAndFilesContainer& a_sosAndFuncNames)
: m_ctorMap(a_sosAndFuncNames) 
{;}

AgentInterfaceForHub* AgentFactory::GenerateAgent(CtorArgs a_args) const
{
    return m_ctorMap.GetCaller(a_args.m_createFunc)(a_args);
}

} // experis