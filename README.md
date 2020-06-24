<p align="center">
<img width="400 height="300 src="https://raw.githubusercontent.com/Brutuski/bryte/master/bryte_logo.png">
</p>

![made-with-python](https://img.shields.io/badge/Made%20with-C-1f425f.svg) ![maintained](https://img.shields.io/badge/Version-1.0-brightgreen)  ![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg) [![license](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/Brutuski/bryte/blob/master/LICENSE)</br>
# Bryte
A simple CLI to change your screen's brightness.<br>
Xbacklight has always been a little buggy and instead of having a program that does a lot of different things, Bryte aims to do few things but be stable. <br>

Bryte can be used to:
+ View current brightness
+ Increment/Decrement brightness<sup>[1](https://github.com/Brutuski/bryte#disclaimer)</sup>
+ Set brightness to desired level

Written in _C_.

## Try out
To simply try out _bryte_:
```
$git clone https://github.com/Brutuski/bryte.git
$cd bryte/src
$gcc bryte.c -pedantic -Wall -Wextra -Os -o bryte
$./bryte -c
```

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
    $bryte -h
    ```
+ To display current brightness level
     ```
    $bryte -c
     ```
+ To increment<sup>[1](https://github.com/Brutuski/bryte#disclaimer)</sup> brightness
    ```
    $bryte -i
    ```
+ To decrement<sup>[1](https://github.com/Brutuski/bryte#disclaimer)</sup> brightness
    ```
    $bryte -d
    ```
+ To manually set brightness levels (_<num> corresponds to the desired brightness levels_)
    ```
    $bryte -s <num>
    ```
+ Version and other information
    ```
    $bryte -v
    ```


## Keybinding with [i3](https://github.com/i3/i3)
Change the key combinations as desired.<br>

+ To increment
    ```
    bindsym $mod+Control+j exec bryte -i
    ```
+ To decrement
    ```
    bindsym $mod+Control+k exec bryte -d
    ```


## Intregration with [Polybar](https://github.com/polybar/polybar)
After installation, simply put this in your Polybar config
```
[module/bryte]
type = custom/script
exec = bryte -c

tail = true
interval = 1

label = "%output%"
```
and include _bryte_ in your bar at the desired positioning.


## Compatibility
Compatible with all Linux systems<sup>[2](https://github.com/Brutuski/bryte#disclaimer)</sup> with an `intel_backlight`. <br>
Check compatibility by running
```
$bryte -p
```
or simply looking up the output of
```
$ls /sys/class/backlight/
```


## Artwork
Logo created by  **Vasundhara Sharma**<br> 
[Github](https://github.com/vasundhasauras), [Behance](https://www.behance.net/vasundhsharma)


## Disclaimer
1: Increment/Decrement in _5%_ steps each.<br>
2: Linux systems with `/sys/class/backlight/` are supported. <br>
3: Support for `intel_backlight` only in v1.0. <br>