#include "process_monitor.h"
#include <filesystem>
#include <fstream>
#include <algorithm>  // ✅ for std::all_of
#include <cctype>     // ✅ for std::isdigit


std::vector<ProcessInfo> getRunningProcesses() {
    std::vector<ProcessInfo> processes;

    for (const auto& entry : std::filesystem::directory_iterator("/proc")) {
        if (!entry.is_directory()) continue;

        const std::string pidStr = entry.path().filename().string();
        if (!std::all_of(pidStr.begin(), pidStr.end(), ::isdigit)) continue;

        std::ifstream commFile(entry.path() / "comm");
        if (!commFile.is_open()) continue;

        ProcessInfo proc;
        proc.pid = std::stoi(pidStr);
        std::getline(commFile, proc.name);

        processes.push_back(proc);
    }

    return processes;
}
