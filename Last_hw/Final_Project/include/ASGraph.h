#ifndef ASGRAPH_H
#define ASGRAPH_H

#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "ASNode.h"
#include "Relationship.h"
#include "AnnouncementCsvParser.h"

struct ParsedRelationship {
    std::uint32_t left_asn = 0;
    std::uint32_t right_asn = 0;
    EdgeKind kind = EdgeKind::PeerToPeer;
};

class GraphCycleError : public std::runtime_error {
public:
    explicit GraphCycleError(const std::string& message)
        : std::runtime_error(message) {}
};

class ASGraph {
public:
    ASGraph() = default;

    ASNode& ensure_node(std::uint32_t asn);
    bool has_node(std::uint32_t asn) const;

    ASNode* find_node(std::uint32_t asn);
    const ASNode* find_node(std::uint32_t asn) const;

    void add_provider_customer(std::uint32_t provider_asn, std::uint32_t customer_asn);
    void add_peer(std::uint32_t asn1, std::uint32_t asn2);

    static ASGraph from_relationships(const std::vector<ParsedRelationship>& relationships);

    std::size_t node_count() const;
    std::size_t provider_customer_edge_count() const;
    std::size_t peer_edge_count() const;

    bool has_provider_customer_cycle() const;
    void validate_acyclic() const;

    void build_propagation_ranks();
    const std::vector<std::vector<std::uint32_t>>& propagation_ranks() const;

    void seed_announcement(std::uint32_t asn, const Announcement& announcement);
    void seed_announcements(const std::vector<SeedAnnouncementRecord>& records);

    void deploy_rov(std::uint32_t asn);
    void deploy_rov(const std::vector<std::uint32_t>& asns);

    void propagate_up();
    void propagate_across_one_hop();
    void propagate_down();
    void propagate_announcements();

    const std::unordered_map<std::uint32_t, std::unique_ptr<ASNode>>& nodes() const;

private:
    void ensure_propagation_ranks_built() const;
    ReceivedFrom determine_received_from(const ASNode& receiver, std::uint32_t sender_asn) const;
    void process_received_queue_for_as(ASNode& node);
    void send_local_rib_to_neighbors(const ASNode& node, const std::vector<std::uint32_t>& neighbor_asns);

    std::unordered_map<std::uint32_t, std::unique_ptr<ASNode>> nodes_;
    std::size_t provider_customer_edge_count_ = 0;
    std::size_t peer_edge_count_ = 0;
    std::vector<std::vector<std::uint32_t>> propagation_ranks_;
};

#endif
