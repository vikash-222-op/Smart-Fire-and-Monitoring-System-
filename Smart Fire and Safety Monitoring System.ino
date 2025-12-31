#include <LiquidCrystal.h>

// ================== PIN DEFINITIONS ==================
const int FLAME_SENSOR = 2;
const int SMOKE_SENSOR = 3;
const int TEMP_SENSOR = 4;
const int RESET_BUTTON = 5;

const int BUZZER = 8;
const int ALARM_LED = 9;
const int POWER_RELAY = 10;
const int CO2_VALVE = 11;
const int POWER_STATUS_LED = 12;

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(6, 7, A0, A1, A2, A3);

// ================== SYSTEM STATES ==================
bool flameDetected = false;
bool smokeDetected = false;
bool tempHigh = false;
bool hazardActive = false;
bool systemLocked = false;

// ================== LCD CONTROL ==================
unsigned long lastScreenChange = 0;
unsigned long lastBlinkTime = 0;
unsigned long lastTempUpdate = 0;

bool blinkState = true;
int screen = 0;
int simulatedTemp = 500;

// ================== SETUP ==================
void setup() {
Serial.begin(9600);

pinMode(FLAME_SENSOR, INPUT_PULLUP);
pinMode(SMOKE_SENSOR, INPUT_PULLUP);
pinMode(TEMP_SENSOR, INPUT_PULLUP);
pinMode(RESET_BUTTON, INPUT_PULLUP);

pinMode(BUZZER, OUTPUT);
pinMode(ALARM_LED, OUTPUT);
pinMode(POWER_RELAY, OUTPUT);
pinMode(CO2_VALVE, OUTPUT);
pinMode(POWER_STATUS_LED, OUTPUT);

digitalWrite(POWER_RELAY, HIGH);
digitalWrite(POWER_STATUS_LED, HIGH);

lcd.begin(16, 2);
randomSeed(analogRead(0));
}

// ================== LOOP ==================
void loop() {
flameDetected = (digitalRead(FLAME_SENSOR) == LOW);
smokeDetected = (digitalRead(SMOKE_SENSOR) == LOW);
tempHigh = (digitalRead(TEMP_SENSOR) == LOW);

hazardActive = flameDetected || smokeDetected || tempHigh;

if (hazardActive && !systemLocked) {
activateEmergency();
}

if (systemLocked) {
emergencyBeep();
checkResetSilently();
}

updateLCD();
}

// ================== EMERGENCY ==================
void activateEmergency() {
systemLocked = true;

digitalWrite(ALARM_LED, HIGH);
digitalWrite(POWER_RELAY, LOW);
digitalWrite(POWER_STATUS_LED, LOW);
digitalWrite(CO2_VALVE, HIGH);
}

// ================== BUZZER ==================
void emergencyBeep() {
static unsigned long lastBeep = 0;
if (millis() - lastBeep > 500) {
digitalWrite(BUZZER, !digitalRead(BUZZER));
lastBeep = millis();
}
}

// ================== RESET (NO DISPLAY HINT) ==================
void checkResetSilently() {
if (digitalRead(RESET_BUTTON) == LOW) {
resetSystem();
delay(1000);
}
}

void resetSystem() {
systemLocked = false;
hazardActive = false;
screen = 0;

digitalWrite(BUZZER, LOW);
digitalWrite(ALARM_LED, LOW);
digitalWrite(CO2_VALVE, LOW);
digitalWrite(POWER_RELAY, HIGH);
digitalWrite(POWER_STATUS_LED, HIGH);
}

// ================== TEMP SIMULATION ==================
int getRandomHighTemp() {
simulatedTemp += random(-15, 20);
if (simulatedTemp < 450) simulatedTemp = 450;
if (simulatedTemp > 650) simulatedTemp = 650;
return simulatedTemp;
}

// ================== LCD UI ==================
void updateLCD() {

// -------- NORMAL MODE --------
if (!systemLocked) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("STATUS : NORMAL");
lcd.setCursor(0,1);
lcd.print("POWER : ON");
delay(600);
return;
}

// -------- BLINK CONTROL --------
if (millis() - lastBlinkTime > 500) {
blinkState = !blinkState;
lastBlinkTime = millis();
}

// -------- SCREEN ROTATION --------
if (millis() - lastScreenChange > 700) {
screen++;
if (screen > 2) screen = 0;
lastScreenChange = millis();
lcd.clear();
}

// -------- SCREEN 0 : HAZARD (BLINK) --------
if (screen == 0) {
if (blinkState) {
lcd.setCursor(0,0);
lcd.print("!! HAZARD !!");

lcd.setCursor(0,1);
lcd.print("    FIRE ");
}
}

// -------- SCREEN 1 : LIVE TEMP --------
else if (screen == 1) {
if (millis() - lastTempUpdate > 1000) {
simulatedTemp = getRandomHighTemp();
lastTempUpdate = millis();
}

lcd.setCursor(0,0);
lcd.print("TEMP : ");
lcd.print(simulatedTemp);
lcd.print(" C");

lcd.setCursor(0,1);
lcd.print("CO2 : ACTIVE");
}

// -------- SCREEN 2 : LOCKED --------
else {
lcd.setCursor(0,0);
lcd.print("POWER : OFF");
lcd.setCursor(0,1);
lcd.print("SYSTEM LOCKED");
}
}
