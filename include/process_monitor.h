#pragma once
#include <vector>
#include <string>

struct ProcessInfo {
    int pid;
    std::string name;
};

std::vector<ProcessInfo> getRunningProcesses();
