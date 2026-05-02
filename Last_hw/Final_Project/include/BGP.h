#ifndef BGP_H
#define BGP_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Policy.h"

class BGP : public Policy {
public:
    BGP() = default;
    ~BGP() override = default;

    void install_local_announcement(const Announcement& announcement) override;
    void enqueue_received_announcement(const Announcement& announcement) override;
    void clear_received_queue() override;

    bool has_local_announcement(const std::string& prefix) const override;
    const Announcement* get_local_announcement(const std::string& prefix) const override;

    const std::unordered_map<std::string, Announcement>& local_rib() const override;
    const std::unordered_map<std::string, std::vector<Announcement>>& received_queue() const override;

private:
    std::unordered_map<std::string, Announcement> local_rib_;
    std::unordered_map<std::string, std::vector<Announcement>> received_queue_;
};

#endif
