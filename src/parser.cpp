#include "../inc/parser.hpp"
#include <fstream>

namespace experis
{

Parser::Parser(std::string a_filePath) 

{
    m_file.open(a_filePath.data());
    
    if (!m_file.is_open())
    {
        throw FailedToOpenIni();
    }
}

Parser::~Parser()
{
    m_file.close();
}

CtorArgs Parser::Parse() 
{
    if (m_file.eof())
    {
        throw NoMoreAgents();
    }
    
    AgentId id;
    getline(m_file, id);
    if (m_file.eof())
    {
        throw NoMoreAgents();
    }
    if ( '[' != id[0] || ']' != id[ id.length() -1 ] )
    {
        throw MissingId();
    }

    AgentType atype;
    getline(m_file, atype);
    if (atype.find("type = ") == std::string::npos) 
    {
        throw MissingType();
    }
    else
    {
        atype.erase(0, 7);
    }
    
    Room room;
    getline(m_file, room);
    if (room.find("room = ") == std::string::npos) 
    {
        throw MissingRoom();
    }
    else
    {
        room.erase(0, 7);
    }

    Floor floor;
    getline(m_file, floor);
    if (floor.find("floor = ") == std::string::npos) 
    {
        throw MissingFloor();
    }
    else
    {
        floor.erase(0, 8);
    }

    std::streampos pos = m_file.tellg();
    Log log;
    ConfigInfo config;
    getline(m_file, log);
    if (log.find("log = ") == std::string::npos)
    {
        config = log;
        config.erase(0, 9);
        log = "DFLT_LOG";
    }
    else
    {
        pos = m_file.tellg();
        getline(m_file, config);
    }

    if (config.find("config = ") == std::string::npos) 
    {
        m_file.seekg(pos);
        getline(m_file, config);
    }

    if (config.find("config = ") == std::string::npos)
    {
        m_file.seekg(pos);
        getline(m_file, config);
        m_file.seekg(pos);

    }

    return CtorArgs(id, atype, floor, room, log, config);
}

} // experis
