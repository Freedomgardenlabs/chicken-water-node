// ================================
// Chicken Water Node – V1
// ================================

// Pin Configuration
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int RELAY_PIN = 7;

// RGB LED pins
const int LED_RED = 3;
const int LED_GREEN = 5;

// Water level configuration
const float TANK_HEIGHT_CM = 20.0;      // Adjust to your container
const float MIN_WATER_PERCENT = 20.0;   // Safety threshold

// =================================

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Safe startup state
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF (LOW trigger module)
}

void loop() {
  float distance = measureDistance();
  float waterPercent = calculateWaterPercent(distance);

  if (waterPercent > MIN_WATER_PERCENT) {
    allowPump();
    setGreen();
  } else {
    stopPump();
    setRed();
  }

  delay(1000);
}

// =================================

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

float calculateWaterPercent(float distance) {
  float waterHeight = TANK_HEIGHT_CM - distance;
  float percent = (waterHeight / TANK_HEIGHT_CM) * 100.0;

  if (percent < 0) percent = 0;
  if (percent > 100) percent = 100;

  return percent;
}

void allowPump() {
  digitalWrite(RELAY_PIN, LOW);  // Relay ON (LOW trigger)
}

void stopPump() {
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF
}

void setGreen() {
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
}

void setRed() {
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, HIGH);
}
