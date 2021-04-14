#pragma once

#include <string>
#include <fstream>
#include "../../inc/common.hpp"
#include "../../inc/commonExc.hpp"
#include "agent_interface_for_hub.hpp"

namespace experis
{

class Parser : public Uncopyable
{
public:
    explicit Parser(std::string a_filePath);
    ~Parser();

public:
    CtorArgs Parse();

private:
    std::fstream m_file;
};

DEFINE_EXCEPTION(FailedToOpenIni, "ERROR: could not open .ini file")
DEFINE_EXCEPTION(MissingId, "ERROR: an agent is missing an ID")
DEFINE_EXCEPTION(MissingType, "ERROR: an agent is missing a type")
DEFINE_EXCEPTION(MissingRoom, "ERROR: an agent is missing a room")
DEFINE_EXCEPTION(MissingFloor, "ERROR: an agent is missing a floor")
DEFINE_EXCEPTION(NoMoreAgents, "Good news! We're done with the .ini file!")


} // experis
