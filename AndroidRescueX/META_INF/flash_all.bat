@echo off
fastboot flash boot google/google/android/Recovery/rescue.img
fastboot flash system system/
fastboot reboot
