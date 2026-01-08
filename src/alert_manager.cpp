#include "alert_manager.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

static std::string currentTimestamp() {
    std::time_t now = std::time(nullptr);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}

void logAlert(const std::string& message) {
    const std::string timestamp = currentTimestamp();

    // Console
    std::cout << "[ALERT] " << timestamp << " - " << message << std::endl;

    // File
    std::ofstream logFile("logs/sentinel.log", std::ios::app);
    if (logFile.is_open()) {
        logFile << "[ALERT] " << timestamp << " - " << message << '\n';
    }
}
