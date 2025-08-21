cmake_minimum_required(VERSION 3.10)
project(nids)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Header location
include_directories(include)
# Npcap SDK paths
include_directories("C:/Windows/System32/Npcap/Include")
link_directories("C:/Windows/System32/Npcap/Lib")

configure_file("${CMAKE_SOURCE_DIR}/config/interface.cfg" 
               "${CMAKE_BINARY_DIR}/config/interface.cfg" COPYONLY)

# Source files
set(SOURCES
    src/main.cpp
    src/entry.cpp
    src/parsers/ethernet.cpp
    src/parsers/ipv4.cpp
    src/utils/decEthernet.cpp
    # src/utils/hex.cpp
    src/config/interface.cpp
    src/utils/decIPv4.cpp
    src/parsers/arp.cpp
    src/parsers/tcp.cpp
    src/parsers/ftp.cpp
    src/nids_dns/packet_capture.cpp
    src/nids_dns/detector.cpp
    src/nids_dns/dns_parser.cpp
    src/nids_dns/utils.cpp
    src/rules/dns.cpp
)

# Compiler warnings
add_compile_options(-Wall -Wextra -Wunused -Wunused-function -Wunused-variable)

# Optional: Dead code elimination
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
add_compile_options(-ffunction-sections -fdata-sections)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")

# Output
add_executable(nids ${SOURCES})
    target_link_libraries(nids pcap)

add_executable(NetGuard
    src/entry.cpp
    src/nids_dns/packet_capture.cpp
    src/nids_dns/detector.cpp
    src/nids_dns/dns_parser.cpp
    src/nids_dns/utils.cpp
)

# Link Npcap libraries for NetGuard
target_link_libraries(NetGuard wpcap Packet ws2_32)

