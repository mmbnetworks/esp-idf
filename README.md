# Hello

I am an example branch of how MMB is using this forked repo.
In this particular branch we are working on testing EMC on the DUT
(in this case the ESP32 on our BRD2x platform) for stability on WiFi and BLE
to do this we use example applications as and example and modified them.

# Which example applications were used?
- [ble_mesh_wifi_coexist](examples/bluetooth/esp_ble_mesh/ble_mesh_wifi_coexist/)
- [ble_mesh_provisioner](examples/bluetooth/esp_ble_mesh/)

# How are the example applications modified
At a high level, we aim to test WiFi annd Bluetooth radion on the DUT simultaneously

We make the DUT device (running `ble_mesh_wifi_coexist`)
- Auto connect to a know WiFi Access Point
- Advertize as ESP_BLE_MESH on Bluetooth

We make the companion device (running `ble_mesh_provisioner`)
- Auto connect to the DUT
- Send generic messages to it periodically to test BLE Connection

# How do we rebuild these examples?

## Setup the environment on Linux

ref:
- [ESP-IDF for Linux and MacOS](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/linux-macos-setup.html)
- [ESP-IDF for Windows](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/windows-setup.html)

- We have tested doing this on ubuntu linux
```bash
// One time setup
git clone git@github.com:mmbnetworks/esp-idf.git mmb-esp-idf-hwtest
cd mmb-esp-idf-hwtest
install.sh // to get tools

// For each time we open a new shell
cd mmb-esp-idf-hwtest
source export.sh


// For each example project
cd /path/to/examples/project-name
idf.py build // first time takes a long time to pull in submodule
```

# How to deploy these examples?
- Get 2x BRD2x `dev.open` units (one for each application)
- Connect them one at a time
- use `idf.py flash` to flash each application

# How to do testing with these units
- [TBD our Confluence worksheet is here](https://mmbnetworks.atlassian.net/wiki/x/q4CQEQE)
