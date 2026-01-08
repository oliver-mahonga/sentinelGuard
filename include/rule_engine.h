#pragma once

#include <vector>
#include "process_monitor.h"
#include "system_stats.h"   // ✅ REQUIRED

void evaluateRules(const std::vector<ProcessInfo>& processes);
void evaluateSystemRules(const SystemStats& stats);
