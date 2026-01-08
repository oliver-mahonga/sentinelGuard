#include <iostream>
#include <thread>
#include <chrono>
#include "process_monitor.h"
#include "rule_engine.h"
#include "system_stats.h"



void printBanner() {
    std::cout << R"(
  ███████╗███████╗███╗   ██╗████████╗██╗███╗   ██╗███████╗██╗     
  ██╔════╝██╔════╝████╗  ██║╚══██╔══╝██║████╗  ██║██╔════╝██║     
  ███████╗█████╗  ██╔██╗ ██║   ██║   ██║██╔██╗ ██║█████╗  ██║     
  ╚════██║██╔══╝  ██║╚██╗██║   ██║   ██║██║╚██╗██║██╔══╝  ██║     
  ███████║███████╗██║ ╚████║   ██║   ██║██║ ╚████║███████╗███████╗
  ╚══════╝╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝
    )" << '\n';
}

int main() {
    printBanner();

    std::cout << "[SentinelGuard] Starting system monitor...\n";

    while (true) {
    auto processes = getRunningProcesses();
    auto stats = getSystemStats();

    std::cout << "[SentinelGuard] Processes: " << processes.size()
              << " | CPU: " << stats.cpuUsagePercent << "%"
              << " | MEM: " << stats.memoryUsagePercent << "%"
              << std::endl;

    evaluateRules(processes);
    evaluateSystemRules(stats);

    std::this_thread::sleep_for(std::chrono::seconds(5));
}




    return 0;
}
