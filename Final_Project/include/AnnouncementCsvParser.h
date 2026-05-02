#ifndef ANNOUNCEMENT_CSV_PARSER_H
#define ANNOUNCEMENT_CSV_PARSER_H

#include <cstdint>
#include <istream>
#include <string>
#include <vector>

#include "Announcement.h"

struct SeedAnnouncementRecord {
    std::uint32_t asn = 0;
    Announcement announcement;
};

class AnnouncementCsvParser {
public:
    static std::vector<SeedAnnouncementRecord> parse_stream(std::istream& input);
    static std::vector<SeedAnnouncementRecord> parse_file(const std::string& path);
};

#endif
