# NetGuard DNS Intrusion Detection System (IDS)

## Overview
NetGuard is a DNS Intrusion Detection System (IDS) designed to monitor DNS traffic on a network interface, detect suspicious or malicious DNS activity, and provide statistics and alerts. It is built in C++ and uses libpcap for packet capture. The system is modular, supporting rule-based and anomaly-based detection.

## Features
- Live DNS packet capture using libpcap
- Rule-based detection engine (custom rules)
- Anomaly detection (e.g., DNS tunneling, DGA domains)
- Real-time statistics and alerting
- Modular codebase for easy extension

## Project Structure
```
NetGuard-main/
├── include/                # Header files
│   ├── nids_dns/           # DNS IDS headers
│   └── rules/              # Rule engine headers
├── src/                    # Source files
│   ├── nids_dns/           # DNS IDS source
│   └── rules/              # Rule engine source
├── rules/                  # Rule files (text)
├── config/                 # Configuration files
├── build/                  # Build output
├── CMakeLists.txt          # Build configuration
└── dns_readme.md           # This file
```

## Prerequisites
- WSL (Ubuntu recommended) or Linux
- C++17 compatible compiler (g++, clang++)
- CMake >= 3.10
- libpcap development libraries
- (Optional) `dig` or `nslookup` for generating DNS traffic

### Install dependencies (Ubuntu/WSL)
```sh
sudo apt update
sudo apt install build-essential cmake libpcap-dev dnsutils
```

## Build Instructions
1. Open a WSL terminal and navigate to the project directory:
   ```sh
   cd /mnt/d/NetGuard-main
   ```
2. Create and enter the build directory:
   ```sh
   mkdir -p build
   cd build
   ```
3. Run CMake and build:
   ```sh
   cmake ..
   make nids
   ```

## Running the DNS IDS
1. Run the program with root privileges (required for packet capture):
   ```sh
   sudo ./nids
   ```
2. By default, it captures on the `eth0` interface and filters for DNS (UDP port 53) traffic.

## Generating DNS Traffic (for testing)
Open another terminal and run:
```sh
ping google.com
# or
nslookup github.com
# or
 dig microsoft.com
```

## Verifying the IDS
- After running the above commands, rerun or check the output of `./nids`.
- You should see statistics showing DNS packets processed.
- If rules match, alerts will be shown in the output.

## Customizing
- **Change interface:** Edit `src/entry.cpp` and set your desired interface in `capture.setInterface("eth0")`.
- **Add rules:** Edit or add rule files in the `rules/` directory.
- **Modify detection logic:** Extend or modify code in `src/nids_dns/detector.cpp` and `src/rules/dns.cpp`.

## Stopping the Program
Press `Ctrl+C` in the terminal running `./nids` to stop the IDS.

## Troubleshooting
- **Permission denied:** Always run with `sudo`.
- **No such device:** Make sure the interface name matches your system (use `ip link` to list interfaces).
- **No DNS packets:** Generate DNS traffic as shown above.

## License
This project is licensed under the MIT License.

---

## Author
**Hayat Ishfaq**  
GitHub: [hayat-ishfaq](https://github.com/hayat-ishfaq)

For further help, open an issue or contact the project maintainer.
