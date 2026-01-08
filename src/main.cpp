#include <iostream>
#include <thread>
#include <chrono>
#include "process_monitor.h"


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
    std::cout << "[SentinelGuard] Active processes: "
              << processes.size() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
}


    return 0;
}
