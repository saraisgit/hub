#include "../inc/event.hpp"

namespace experis
{

Event::Event(std::string a_timestamp, std::string a_type, std::string a_floor, std::string a_room, std::string a_info)
: m_timestamp(a_timestamp)
, m_type(a_type)
, m_floor(a_floor)
, m_room(a_room)
, m_additionalInfo(a_info)
{
    // empty
}

} // experis