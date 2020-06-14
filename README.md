<div style="text-align:center"><img src="https://raw.githubusercontent.com/Brutuski/bryte/master/bryte_logo.png?token=ABV7LMPI5G4PUPKL5PQDDIS64ZNY4" /></div>

![made-with-python](https://img.shields.io/badge/Made%20with-C-1f425f.svg) ![maintained](https://img.shields.io/badge/Version-1.0-brightgreen)  ![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg) [![license](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/Brutuski/bryte/blob/master/LICENSE)</br>
# Bryte
A simple CLI to change your screen's brightness.<br>
Written in _C_.

## Install
Installed in `/usr/bin/`<br>
To Install:
```
make
sudo make install
```

## Usage
+ To get to the help section
    ```
    $bryte
    $bryte --help
    $bryte -h
    ```
+ To display current brightness level
     ```
    $bryte -c
     ```
+ To increment<sup>[1](##DIsclaimer)</sup> brightness
    ```
    $bryte -i
    ```
+ To decrement<sup>1</sup> brightness
    ```
    $bryte -d
    ```
+ To manually set brightness levels (_<num> corresponds to the desired brightness levels_)
    ```
    $bryte -s <num>
    ```
+ Version and other information
    ```
    $bryte --version
    $bryte -v
    ```

## Compatibility
Compatible with all Linux systems<sup>[2](##Disclaimer)</sup>.<br>
It reads your backlight card<sup>[3]()</sup>

## Artwork
Logo created by [Vasundhara Sharma](https://github.com/vasundhasauras), [Behance](https://www.behance.net/vasundhsharma)

## Disclaimer
### 1: Increment/Decrement steps are set at 5% <br>
### 2: Linux systems with `/sys/class/backlight/` are supported. <br>
### 3: Supported backlight cards are `intel_backlight` and `acpi_video0`.
