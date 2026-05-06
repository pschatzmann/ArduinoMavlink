
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 pschatzmann

#pragma once

// --- Core ---
#ifndef MAVLINK_ALIGNED_FIELDS
#define MAVLINK_ALIGNED_FIELDS      1
#endif

#ifndef MAVLINK_CRC_EXTRA
#define MAVLINK_CRC_EXTRA           1
#endif

#ifndef MAVLINK_COMMAND_24BIT
#define MAVLINK_COMMAND_24BIT       1
#endif

// --- Version ---
#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION             2
#endif

#ifndef MAVLINK_PROTOCOL_VERSION
#define MAVLINK_PROTOCOL_VERSION    2
#endif

// --- Buffers ---
#ifndef MAVLINK_COMM_NUM_BUFFERS
#define MAVLINK_COMM_NUM_BUFFERS    1
#endif

#ifndef MAVLINK_MAX_PAYLOAD_LEN
#define MAVLINK_MAX_PAYLOAD_LEN     255
#endif

// --- Identity ---
#ifndef MAVLINK_SYSTEM_ID
#define MAVLINK_SYSTEM_ID           255
#endif

#ifndef MAVLINK_COMPONENT_ID
#define MAVLINK_COMPONENT_ID        200
#endif

// --- Signing ---
#ifndef MAVLINK_USE_SIGNING
#define MAVLINK_USE_SIGNING         0
#endif

// --- Convenience ---
//#define MAVLINK_USE_CONVENIENCE_FUNCTIONS

// --- Logging ---
#ifndef MAVLINK_MAX_LOG_SIZE
#define MAVLINK_MAX_LOG_SIZE       120
#endif

// --- ESP32 Logging ---
#ifndef MAVLINK_USE_ESP_LOGGER
#define MAVLINK_USE_ESP_LOGGER      true
#endif

// ignore warnings about taking the address of packed struct members, which is
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
