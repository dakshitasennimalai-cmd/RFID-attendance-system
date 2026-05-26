/*
  ============================================
  RFID Attendance System
  By: Dakshita Sennimalai
  College: ECE Department
  Year: 2nd Year
  
  Components:
  - Arduino Uno
  - RC522 RFID Module
  - 16x2 LCD with I2C
  ============================================
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
#define RST_PIN   9
#define SS_PIN    10

// Create objects
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Registered RFID card UIDs (add your card UIDs here)
String registeredCards[] = {
  "A1B2C3D4",   // Student 1
  "E5F6G7H8",   // Student 2
  "I9J0K1L2"    // Student 3
};

String studentNames[] = {
  "Ravi Kumar",
  "Priya Singh",
  "Amit Sharma"
};

int totalStudents = 3;
int attendanceCount[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("RFID Attendance");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");
  
  Serial.println("RFID Attendance System Started");
  Serial.println("Scan a card...");
}

void loop() {
  // Check if a card is present
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  // Read card UID
  String cardUID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    cardUID += String(rfid.uid.uidByte[i], HEX);
  }
  cardUID.toUpperCase();
  
  Serial.print("Card UID: ");
  Serial.println(cardUID);
  
  // Check if card is registered
  bool found = false;
  for (int i = 0; i < totalStudents; i++) {
    if (cardUID == registeredCards[i]) {
      found = true;
      attendanceCount[i]++;
      
      // Show on LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(studentNames[i]);
      lcd.setCursor(0, 1);
      lcd.print("Present! Count:");
      lcd.print(attendanceCount[i]);
      
      Serial.print(studentNames[i]);
      Serial.println(" - Marked Present");
      
      delay(2000);
      break;
    }
  }
  
  if (!found) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Unknown Card!");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
    
    Serial.println("Unknown card - Access Denied");
    delay(2000);
  }
  
  // Reset LCD to waiting screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

