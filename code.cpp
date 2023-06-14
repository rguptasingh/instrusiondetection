#include <HCSR04.h> 
#include <kiFiNINA.h>
#include <EMalISender.h>
#include <string.h>
/*
/////////////////////////////////////
SONIC
/////////////////////////////////////
*

#define TRIG 2 #define ECHO 3

UltrasonicDistanceSensor distancesensor (TRIG, ECHO);

int numbs[10]; int counter = 0;

int runs = 0;

int mid = 0; int lastMid = 8;

WIFI / MAIL

EMailSender emailSend("movement DetectedSuperSonic@gmail.com", "Toor1234");

int status WL_IDLE_STATUS;

char ssid[]"AndroidAP0954"; char pass[] = "vdxu2544";

WiFiSSLClient client;

void connectToAP()X

while(status = WL_CONNECTED) {

Serial.print("Connecting to SSID: "); Serial.println(ssid); status WiFi.begin(ssid, pass);
