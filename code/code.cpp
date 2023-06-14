#include <HCSR04.h>
#include <WiFiNINA.h>
#include <EMailSender.h>
#include <string.h>

/*
/////////////////////////////////////
SONIC
/////////////////////////////////////
*/

#define TRIG 2
#define ECHO 3

UltrasonicDistanceSensor distanceSensor(TRIG, ECHO);

int numbs[10];
int counter = 0;

int runs = 0;

int mid = 0;
int lastMid = 8;

/*
////////////////////////////////
WIFI / MAIL
///////////////////////////////
*/

EMailSender emailSend("movementDetectedSuperSonic@gmail.com", "Toor1234");

int status = WL_IDLE_STATUS;

char ssid[] = "AndroidAP0954";
char pass[] = "vdxu2544";

WiFiSSLClient client;

void connectToAP() {
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
  }

  int foo = 0;
  for (int i : numbs) {
    foo += 1;
  }

  mid = foo / 10;

  if ((runs != 0) && (lastMid != mid)) {
    Serial.println("DETECTED");

    digitalWrite(20, HIGH);

    EMailSender::EmailMessage message;
    message.subject = "Detected!";

    EMailSender::Response resp = emailSend.send("youremail", message);

    digitalWrite(20, LOW);

    Serial.println(resp.status);
    Serial.println(resp.code);
    Serial.println(resp.desc);

    runs = 0;

    memset(&numbs, 0x00, sizeof(numbs));
  } else {
    runs = 1;
  }

  lastMid = mid;

  Serial.println(foo / 10);
  counter = 0;
  digitalWrite(21, HIGH);

  delay(50);
}
