#include <iostream>
#include "nids_dns/packet_capture.hpp"
#include "nids_dns/detector.hpp"
#include "nids_dns/dns_parser.hpp"
#include "nids_dns/utils.hpp"

int run_entry() {
    std::cout << "[*] Starting DNS Intrusion Detection..." << std::endl;

    PacketCapture capture;
    DNSDetector detector;

    // Use the correct interface for WSL
    capture.setInterface("eth0");
    capture.setFilter("udp port 53");   // capture only DNS packets

    if (!capture.startLiveCapture()) {
        std::cerr << "[-] Failed to start capture: " << capture.getLastError() << std::endl;
        return 1;
    }


    // Set callback to analyze each DNS packet
    capture.setPacketCallback([&detector](const DNSPacket& packet) {
        detector.analyzePacket(packet);
    });

    // Process packets (unlimited)
    capture.processPackets();

    capture.printStatistics();

    std::cout << "[*] DNS IDS finished." << std::endl;
    return 0;
}
