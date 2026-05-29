# ESP32-S3 Hardware Analysis Toolkit

A modular embedded hardware analysis toolkit built on the ESP32-S3 using ESP-IDF.

The goal of this project is to gradually evolve from a simple UART sniffer into a portable hardware debugging and protocol analysis platform capable of inspecting UART, I2C, SPI, BLE, and other communication interfaces.

---

## Current Status

### Phase 1 - UART Capture Foundation

Implemented:

* UART packet capture
* Timestamp generation
* Modular architecture
* Event-based capture system
* Hex data visualization
* ASCII data visualization
* Configurable UART settings
* FreeRTOS-based capture task

The project currently captures UART traffic from another microcontroller and converts it into structured capture events.

---

## Project Goals

Instead of building another sensor-based IoT project, this project focuses on low-level embedded engineering concepts such as:

* Protocol analysis
* Embedded debugging tools
* Real-time data acquisition
* DMA-based capture
* Logic analyzer design
* Signal analysis
* Hardware reverse engineering

---

## Current Architecture

```text
UART Hardware
      ↓
UART Capture Layer
      ↓
Capture Event
      ↓
Ring Buffer
      ↓
Logger
      ↓
Console Output
```

---

## Project Structure

```text
main/
│
├── main.c
│
├── config.h
│
├── uart_sniffer.c
├── uart_sniffer.h
│
├── logger.c
├── logger.h
│
├── timestamp.c
├── timestamp.h
│
├── ring_buffer.c
├── ring_buffer.h
│
└── capture_types.h
```

---

## Module Overview

### main.c

Application entry point.

Responsible for:

* System startup
* Initializing capture modules

---

### config.h

Centralized project configuration.

Examples:

* UART port
* RX pin
* Baud rate
* Buffer sizes
* Timeouts

---

### uart_sniffer

Handles:

* UART driver initialization
* UART packet capture
* FreeRTOS capture task

Outputs structured capture events.

---

### timestamp

Provides microsecond timestamps using:

```c
esp_timer_get_time()
```

Every captured packet receives a timestamp.

---

### capture_types

Defines the core capture event structure.

```c
typedef struct
{
    uint64_t timestamp_us;

    uint16_t length;

    uint8_t data[256];

} capture_event_t;
```

All future protocols will use this common event format.

---

### ring_buffer

Currently acts as a simple forwarding layer.

Future versions will implement:

* Circular buffering
* Overflow handling
* Event queues
* DMA integration

---

### logger

Responsible for presenting captured data.

Current outputs:

* HEX view
* ASCII view
* Timestamps

Example:

```text
[123456 us]

HEX   : 48 45 4C 4C 4F
ASCII : HELLO
```

---

## Hardware Setup

### Generator ESP32-S3

Transmits UART data.

Example:

```text
GPIO17 -> TX
```

---

### Toolkit ESP32-S3

Receives UART traffic.

Example:

```text
GPIO18 -> RX
```

---

### Wiring

```text
Generator GPIO17  ---> Toolkit GPIO18
Generator GND     ---> Toolkit GND
```

---

## Development Roadmap

### Phase 1 - UART Foundation

Status: In Progress

* UART capture
* Timestamping
* Logging
* Event architecture
* Ring buffer foundation

---

### Phase 2 - Real-Time Capture

Planned:

* DMA-based capture
* Trigger system
* Waveform storage
* Performance optimization

---

### Phase 3 - Protocol Analysis

Planned:

* UART framing
* Packet decoding
* Protocol parsing
* Event filtering

---

### Phase 4 - Multi-Protocol Support

Planned:

* I2C scanner
* I2C decoding
* SPI monitoring
* SPI decoding

---

### Phase 5 - Hardware Analysis Features

Planned:

* Signal generator
* Logic analyzer mode
* Oscilloscope-lite
* Trigger engine

---

### Phase 6 - Advanced Toolkit Features

Planned:

* BLE analysis
* WiFi frame analysis
* Web dashboard
* SD card logging
* Remote streaming

---

## Learning Objectives

This project is designed to develop practical skills in:

* ESP-IDF
* FreeRTOS
* UART communication
* Embedded architecture
* Ring buffers
* Real-time systems
* Protocol analysis
* DMA
* Embedded debugging

---

## Long-Term Vision

The long-term goal is to create a portable hardware analysis platform that combines features commonly found in:

* Logic analyzers
* Serial protocol analyzers
* Debugging tools
* Signal generators

while remaining fully open-source and ESP32-S3 based.
# ESP32-S3-Hardware-Analysis-Toolkit
