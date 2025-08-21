#pragma once
#include <string>
#include <vector>
#include <memory>
#include "nids_dns/dns_parser.hpp"
#include "nids_dns/detector.hpp"

class DNSRuleEngine {
public:
    DNSRuleEngine();
    bool loadRules(const std::string& filename);
    std::vector<std::string> match(const DNSPacket& packet) const;
private:
    std::vector<DNSRule> rules_;
};
