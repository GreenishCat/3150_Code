#ifndef ASNODE_H
#define ASNODE_H

#include <cstdint>
#include <memory>
#include <unordered_set>

#include "Policy.h"

struct ASNode {
    std::uint32_t asn = 0;
    std::unordered_set<std::uint32_t> providers;
    std::unordered_set<std::uint32_t> customers;
    std::unordered_set<std::uint32_t> peers;
    std::unique_ptr<Policy> policy;
    int propagation_rank = -1;

    ASNode() = default;
    explicit ASNode(std::uint32_t value) : asn(value) {}
};

#endif
