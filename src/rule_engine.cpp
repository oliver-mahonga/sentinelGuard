#include "rule_engine.h"
#include "alert_manager.h"
#include <unordered_set>
#include <string>

void evaluateRules(const std::vector<ProcessInfo>& processes) {
    static const std::unordered_set<std::string> suspiciousNames = {
        "keylogger",
        "cryptominer",
        "unknown_app"
    };

    for (const auto& proc : processes) {
        if (suspiciousNames.count(proc.name)) {
            logAlert(
                "Suspicious process detected: " +
                proc.name + " (PID " + std::to_string(proc.pid) + ")"
            );
        }
    }
}

void evaluateSystemRules(const SystemStats& stats) {
    if (stats.cpuUsagePercent > 85.0) {
        logAlert(
            "High CPU usage detected: " +
            std::to_string(stats.cpuUsagePercent) + "%"
        );
    }

    if (stats.memoryUsagePercent > 80.0) {
        logAlert(
            "High memory usage detected: " +
            std::to_string(stats.memoryUsagePercent) + "%"
        );
    }
}
