/*
 * Iperf example - declarations of command registration functions.
 *
 * SPDX-FileCopyrightText: 2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
#pragma once

// Register WiFi functions
void register_wifi(void);
void initialise_wifi(void);

/**
 * @brief The public API wrapper to call wifi_cmd_sta_join() programmatically
 *
 * @return true if connection is successful, false otherwise
 */
bool wifi_STAJoin(const char *aSSID, const char *aPass);
