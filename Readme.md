# AndroidRescueX

## Overview

This project is a custom ROM. It provides a unique user interface and features, allowing users to flash various modifications, manage backups, and customize their Android experience. All frameworks and UI elements have been developed from scratch to ensure a smooth and customizable user experience.

## Features

- Independent custom recovery environment.
- Custom UI and frameworks tailored for ease of use.
- Fast and efficient flashing of custom ROMs, kernels, and mods.
- Backup and restore functionality.
- Support for various file systems.

- ## Note
- This project is currently in testing so, pls check the source code before use, also it currently supports xioami devices (Redmi Note 13R)

## Installation Instructions

To flash this custom ROM on your device, follow these steps:

1. **Download the ROM**: Ensure you have the latest version of the Custom TWRP Alternative ROM.

2. **Boot into Fastboot Mode**:
   - Power off your device.
   - Press and hold the appropriate key combination (usually Volume Down + Power) to enter Fastboot mode.

3. **Connect to PC**:
   - Connect your device to your PC using a USB cable.

4. **Flash the ROM**:
   - Open a command prompt or terminal window.
   - Navigate to the folder where your ROM files are located.
   - Run the following command (for Windows):
     ```bat
     flash_all.bat
     ```
5. **For Linux and MacOS**: Support for these 2 platforms are coming soon. :)

6. **Reboot**:
   - After flashing, your device should reboot automatically. If not, use the command:
     ```sh
     fastboot reboot
     ```

## Note

- Ensure that you have **ADB** and **Fastboot** installed on your PC.
- Back up your data before flashing to avoid data loss.
- This ROM is intended for advanced users familiar with flashing custom ROMs and recovery environments.

## License

This project is open-source. You can use, modify, and distribute it as long as proper credit is given to the original authors.
