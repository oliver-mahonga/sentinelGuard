# SentinelGuard

**SentinelGuard** is a lightweight, Linux-based system monitoring and anomaly detection tool written in modern **C++ (C++17)**. It acts as a small sentinel on your system — continuously observing processes, CPU usage, and memory usage, and raising alerts when suspicious or abnormal behavior is detected.

This project is designed to demonstrate **systems programming**, **performance monitoring**, and **security-oriented thinking** using clean, modular C++.

---

## Features

* **Process Monitoring**
  Detects running processes directly from `/proc` without shell commands.

* **Rule-Based Detection Engine**
  Flags suspicious process names using a simple but extensible rule engine.

* **CPU & Memory Anomaly Detection**
  Detects high CPU or RAM usage using kernel statistics.

* **Alert Manager**

  * Console alerts
  * Persistent logging to `logs/sentinel.log`

* **Modular Architecture**
  Clean separation of concerns using headers and implementation files.

---

## Architecture Overview

```
+-------------------+
|   main.cpp        |
|-------------------|
| - Control loop    |
| - Scheduling      |
+---------+---------+
          |
          v
+-------------------+        +---------------------+
| Process Monitor   | -----> | Rule Engine         |
| (/proc scanning)  |        | - Process rules     |
+-------------------+        | - System rules      |
                             +----------+----------+
                                        |
                                        v
                             +---------------------+
                             | Alert Manager       |
                             | - Console alerts    |
                             | - File logging      |
                             +---------------------+

+-------------------+
| System Stats      |
| - CPU usage       |
| - Memory usage    |
+-------------------+
```

---

## Project Structure

```
SentinelGuard/
├── src/
│   ├── main.cpp
│   ├── process_monitor.cpp
│   ├── system_stats.cpp
│   ├── rule_engine.cpp
│   └── alert_manager.cpp
├── include/
│   ├── process_monitor.h
│   ├── system_stats.h
│   ├── rule_engine.h
│   └── alert_manager.h
├── config/
│   └── rules.conf
├── logs/
│   └── sentinel.log
├── CMakeLists.txt
└── README.md
```

---

## Build and Run

### Requirements

* Linux
* C++17 compatible compiler (g++ or clang)
* CMake 3.16 or newer

### Build

```bash
mkdir build
cd build
cmake ..
make
```

### Run

```bash
./sentinel_guard
```

---

## Purpose

SentinelGuard is a portfolio-focused project intended to demonstrate:

* Linux system programming
* Performance and resource monitoring
* Rule-based detection logic
* Clean C++ architecture suitable for security and automation systems

---
