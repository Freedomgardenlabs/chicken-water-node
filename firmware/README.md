# Firmware Documentation – Chicken Water Node V1

## Overview

This firmware controls:

- Water pump activation via LOW-trigger relay
- Ultrasonic water level monitoring
- RGB LED system status indication
- Dry-run protection logic

---

## Functional Logic

### 1. Distance Measurement

The HC-SR04 ultrasonic sensor measures the distance between the sensor and water surface.

Distance is converted into water level percentage.

---

### 2. Water Threshold Control

If water level > 20%:
- Pump operation allowed
- LED → Green

If water level ≤ 20%:
- Pump forced OFF
- LED → Red
- Dry-run protection engaged

---

## Relay Logic

The relay is configured as:

LOW = ON  
HIGH = OFF  

This configuration ensures safe default state on startup.

---

## LED Logic

RGB LED states:

Green:
- System operational
- Safe water level

Red:
- Water below threshold
- Refill required

---

## Safety Features

- Pump dry-run prevention
- Default safe relay state
- Continuous water level monitoring loop

---

## Future Firmware Upgrades

- Hysteresis threshold control
- Sensor error detection
- Serial telemetry output
- Integration with ADAM communication protocol
