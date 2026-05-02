#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <cstdint>
#include <string>
#include <vector>

#include "Relationship.h"

struct Announcement {
    std::string prefix;
    std::vector<std::uint32_t> as_path;
    std::uint32_t next_hop_asn = 0;
    ReceivedFrom received_from = ReceivedFrom::Origin;
    bool rov_invalid = false;
};

#endif
