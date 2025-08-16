# STM32F411 Bare-Metal Temperature & Humidity Monitor

## Overview

This project measures temperature and humidity using a DHT22 sensor and displays the readings on an SSD1360 OLED screen. It is implemented with bare-metal C (no HAL/LL or RTOS) on an STM32
F411 microcontroller. The goal is to demonstrate direct register manipulation and peripheral configuration for embedded development.

## Features

- Reads temperature and humidity from DHT22 sensor
- Displays readings on SSD1360 OLED
- Bare-metal code 
- Simple and efficient embedded design

## Hardware Requirements

- STM32F411 microcontroller 
- DHT22 Temperature & Humidity sensor
- SSD1360 OLED display (128x64)
- Jumper wires
- Breadboard 

## Wiring Diagram

| Device      | STM32F411 Pin | Notes                |
|-------------|---------------|----------------------|
| DHT22 Data  | PA8           | 10k pull-up resistor  |
| SSD1360 SCL | PB8           | I2C Clock            |
| SSD1360 SDA | PB9           | I2C Data             |
| GND         | GND           | Common ground        |
| VCC         | 3.3V          | Power supply         |


<img width="1024" height="781" alt="Screen-Shot-2021-12-23-at-6 31 42-AM-2048x1556" src="https://github.com/user-attachments/assets/a96e0f7a-d14a-4c10-b510-62e2e223b795" />





## Code Structure

- `/src` - main and peripheral drivers
- `/inc` - header files


## Example Display

```
Temp: 25.3°C
Hum:  64.2%
```


