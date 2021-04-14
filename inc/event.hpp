#pragma once
#include <string>
#include "commonTypedefs.hpp"

namespace experis {

struct Event
{
    Event(Timestamp a_timestamp, EventType a_type, Floor a_floor, Room a_room, AdditionalInfo a_info = "");

    Timestamp m_timestamp;
    EventType m_type;
    Floor m_floor;
    Room m_room;
    AdditionalInfo m_additionalInfo;
};

} // experis