#pragma once

struct SystemStats {
    double cpuUsagePercent;
    double memoryUsagePercent;
};

SystemStats getSystemStats();
