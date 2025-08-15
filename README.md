# STM32F411 Bare-Metal Temperature & Humidity Monitor

## Overview

This project measures temperature and humidity using a DHT22 sensor and displays the readings on an SSD1360 OLED screen. It is implemented with bare-metal C (no HAL/LL or RTOS) on an STM32<img width="1472" height="969" alt="1" src="https://github.com/user-attachments/assets/37a9c37d-2d10-45cf-b129-6fc409adbc25" />
F411 microcontroller. The goal is to demonstrate direct register manipulation and peripheral configuration for embedded development.

## Features

- Reads temperature and humidity from DHT22 sensor
- Displays readings on SSD1360 OLED
- Bare-metal code (no libraries except minimal SSD1360 driver)
- Simple and efficient embedded design

## Hardware Requirements

- STM32F411 microcontroller (e.g., STM32F411CEU6 "Black Pill")
- DHT22 Temperature & Humidity sensor
- SSD1360 OLED display (128x64)
- Jumper wires
- Breadboard (optional)

## Wiring Diagram

| Device      | STM32F411 Pin | Notes                |
|-------------|---------------|----------------------|
| DHT22 Data  | PA0           | Pull-up resistor req |
| SSD1360 SCL | PB6           | I2C Clock            |
| SSD1360 SDA | PB7           | I2C Data             |
| GND         | GND           | Common ground        |
| VCC         | 3.3V/5V       | Power supply         |

*(Update pin numbers according to your schematic)*

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/tienhoang1597/stm32f411-dht22-ssd1360.git
cd stm32f411-dht22-ssd1360
```

### 2. Build & Flash

- Open the project in your IDE (STM32CubeIDE, CLion, VSCode + ARM toolchain)
- Compile the code
- Flash the firmware using ST-Link or compatible programmer

### 3. Run

- Power the board
- The OLED should display real-time temperature and humidity values

## Code Structure

- `/src` - main and peripheral drivers
- `/inc` - header files
- `/docs` - datasheets, wiring diagrams

## Example Display

```
Temp: 25.3°C
Hum:  64.2%
```

## Contributing

Pull requests and suggestions are welcome! Please open an issue for major changes.

## License

MIT License

## Author

[tienhoang1597](https://github.com/tienhoang1597)

---

*For more details, see the DHT22 and SSD1360 datasheets in the `/docs` folder.*
