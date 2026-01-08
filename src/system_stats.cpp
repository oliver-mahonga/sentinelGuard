#include "system_stats.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

static long long readCPUTime(long long& idleTime) {
    std::ifstream file("/proc/stat");
    std::string cpu;
    long long user, nice, system, idle, iowait, irq, softirq, steal;

    file >> cpu >> user >> nice >> system >> idle >> iowait
         >> irq >> softirq >> steal;

    idleTime = idle + iowait;
    return user + nice + system + idle + iowait + irq + softirq + steal;
}

static double calculateCPUUsage() {
    long long idle1, total1;
    total1 = readCPUTime(idle1);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    long long idle2, total2;
    total2 = readCPUTime(idle2);

    long long totalDiff = total2 - total1;
    long long idleDiff  = idle2 - idle1;

    return 100.0 * (totalDiff - idleDiff) / totalDiff;
}

static double calculateMemoryUsage() {
    std::ifstream file("/proc/meminfo");
    std::string key;
    long long value;
    std::string unit;

    long long memTotal = 0;
    long long memAvailable = 0;

    while (file >> key >> value >> unit) {
        if (key == "MemTotal:") memTotal = value;
        else if (key == "MemAvailable:") {
            memAvailable = value;
            break;
        }
    }

    return 100.0 * (memTotal - memAvailable) / memTotal;
}

SystemStats getSystemStats() {
    SystemStats stats;
    stats.cpuUsagePercent = calculateCPUUsage();
    stats.memoryUsagePercent = calculateMemoryUsage();
    return stats;
}
