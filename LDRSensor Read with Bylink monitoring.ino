#define BLYNK_TEMPLATE_ID "TMPL6GCrdV2np"
#define BLYNK_TEMPLATE_NAME "CAHAYAAAA"
#define BLYNK_AUTH_TOKEN "q8bX_ZJjuvfUllztylqfna64_o-awqYY"

#include <BlynkSimpleEsp32.h>

#define AO_PIN 32  // ESP32's pin GPIO36 connected to AO pin of the LDR module
#define LED_PIN 15

void readSensor() {
  int lightValue = analogRead(AO_PIN);

  Serial.print("The AO value: ");
  Serial.println(lightValue);

    // Send
  Blynk.virtualWrite(V1, lightValue);

  int lightreshold = 1200;

    // Check if the light value exceeds 3900
  if (lightValue < lightreshold) {
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin("YOSI", "ALISANDRO");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi Connected");
  Blynk.begin(BLYNK_AUTH_TOKEN, "YOSI", "ALISANDRO");
  Serial.println("Blynk Connected");
}

void loop() {
  Blynk.run();
  readSensor();
  delay(500);
}