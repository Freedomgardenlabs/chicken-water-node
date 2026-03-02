# Hardware Specification – Chicken Water Node V1

## Core Components

- Arduino (Uno / Nano compatible)
- 5V Submersible Water Pump
- Optocoupler Isolated Relay Module (LOW trigger)
- HC-SR04 Ultrasonic Sensor (Water Level Monitoring)
- RGB LED (System Status Indicator)
- External 5V Power Supply
- Basic water filtration system

---

## Functional Logic

### Water Level Monitoring

The ultrasonic sensor continuously measures water level.

If water level falls below 20% threshold:

- Pump is automatically turned OFF
- Dry-run protection is activated
- System enters low-water state

---

### Visual Status Feedback (RGB LED)

The RGB LED provides immediate system status:

- 🟢 Green → Water level OK
- 🔴 Red → Water level below 20% (Refill required)

This allows quick visual inspection without serial monitoring.

---

## Electrical Design

### Relay Configuration
- LOW-trigger activation
- Optocoupler isolation between control logic and load
- External power source dedicated to pump

### Sensor Integration
- Ultrasonic distance measurement
- Threshold-based logic control
- Calibrated minimum water height parameter

### LED Integration
- Digital output control from Arduino
- Status-based color switching logic

---

## Power Strategy (V1)

- Direct external 5V supply
- Shared ground between Arduino and relay module
- Pump powered separately through relay

---

## Known Limitations (V1)

- No battery backup
- No solar integration
- No telemetry feedback
- No water consumption analytics

---

## Planned Improvements (V1.1)

- Solar panel integration
- Battery bank
- Remote monitoring
- Water usage tracking
- Expanded sensor network

---

## Long-Term Direction

The hardware will evolve into a modular autonomous node capable of:

- Independent power management
- Sensor-based optimization
- Communication with central control system (ADAM)
