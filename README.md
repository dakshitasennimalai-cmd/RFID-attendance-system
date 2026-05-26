
# RFID Attendance System

An Arduino-based automatic attendance marking system using RFID technology. Students scan their RFID card and attendance is instantly recorded and displayed on an LCD screen — no manual marking needed.

## Problem it solves
Manual attendance is slow and can be manipulated. This system automates the process using unique RFID cards assigned to each student.

## Components used
| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| RC522 RFID Module | 1 |
| RFID Cards / Key Tags | As needed |
| 16x2 LCD Display | 1 |
| I2C Module (for LCD) | 1 |
| Jumper Wires | Several |
| Breadboard | 1 |
| 9V Battery / USB Power | 1 |

## Circuit connections
| RC522 Pin | Arduino Uno Pin |
|---|---|
| SDA | Pin 10 |
| SCK | Pin 13 |
| MOSI | Pin 11 |
| MISO | Pin 12 |
| RST | Pin 9 |
| 3.3V | 3.3V |
| GND | GND |

## Libraries required
- MFRC522 — for RC522 RFID module
- LiquidCrystal_I2C — for LCD display
- SPI — built-in Arduino library

## How to run
1. Connect all components as per circuit connections above
2. Install MFRC522 and LiquidCrystal_I2C libraries in Arduino IDE
3. Upload the .ino file to Arduino Uno
4. Power the Arduino via USB or 9V battery
5. Tap an RFID card near the reader
6. Attendance status appears on LCD

## What I learned
- SPI communication protocol between Arduino and RFID module
- How RFID technology works — unique card IDs and reader communication
- Interfacing LCD display using I2C to reduce pin usage
- Practical application of embedded systems in real-world problems

## Future improvements
- Store attendance data on SD card or web server
- Add timestamps using RTC module
- Build a web dashboard to view attendance records

## Author
2nd Year ECE Student | Bengaluru this and what shd i do i uploaded the word in my rep
