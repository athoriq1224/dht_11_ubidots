#define BLYNK_PRINT Serial #include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <MFRC522.h> // import file MFRC522 yang sudah kita install #include <Servo.h>

char auth[] = "BBFF-0kFPjZRJqbINSZ3Z6F8MV4cWgIIlyB"; 
char ssid[] = "Realme3";
char pass[] = "12345678";

#define SDA_PIN D2 // mendefinisikan SDA pin ke D2
#define RST_PIN D1 // mendefinisikan RST pin ke D1
#define motor D4

Servo servo;
MFRC522 mfrc522(SDA_PIN, RST_PIN); // setting mfrc dengan SDA dan RST WidgetLCD lcd(V1); // setting pin virtual LCD ke V1 di aplikasi blynk
void setup() {
  Serial.begin(9600);
  SPI.begin(); // Initiate SPI bus
  Blynk.begin(auth, ssid, pass); mfrc522.PCD_Init(); // Inisiasi MFRC522 card pinMode(motor, OUTPUT);
  Serial.println("Approximate your card to the reader..."); // pesan untuk mentap kartu
  Serial.println();
}
void loop() {
  Blynk.run();
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  // menampilkan UID di serial Monitor
  Serial.print("UID tag :"); String content = "";
  byte letter;
  // berfungsi untuk mengubah ID dari Kartu menjadi kode Hexa seperti 04
  EA F0 2B
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); Serial.print(mfrc522.uid.uidByte[i], HEX); content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println(); Serial.print("Message : ");
  content.toUpperCase(); // UID dijadikan Huruf besar semua
  if (content.substring(1) == "04 EA F0 2B") // masukkan ID kartu / E-KTP disini
    LCD blynk
  }
else
{
  {
    lcd.clear();
    lcd.print(0, 0, "UID for Card is");
    // Menampilkan UID di
    lcd.print(0, 1, content);
    delay(1000);
    buka(); // fungsi untuk menggerakkan servo
    lcd.clear();
    lcd.print(0, 0, "Invalid card"); ditolak di LCD blynk
    // Menampilkan pesan
  }
  lcd.print(0, 1, "Access Denied");
}
void buka() { // membuat fungsi untuk menggerakkan servo servo.attach(motor);
  servo.write(90);
  delay(2000);

  servo.write(0);
}
