/*******************************************************************
 *  An example of usisng the InstagramStats library to get
 *  info on a given user
 *
 *  Written by Brian Lough
 *  https://www.youtube.com/channel/UCezJOfu7OtqGzd5xrP3q6WA
 *******************************************************************/

#include "InstagramStats.h"

 // ----------------------------
 // Standard Libraries - Already Installed if you have ESP32 set up
 // ----------------------------

#include <WiFi.h>
#include <WiFiClientSecureBearSSL.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

//------- Replace the following! ------
char ssid[] = "SSID";       // your network SSID (name)
char password[] = "PASSWORD";  // your network key

String INSTAGRAM_ACCESS_TOKEN = "ENTER_YOUR_APP_TOKEN";
String IG_USER_ID = "ENTER_YOUR_IG_USER_ID";

WiFiClientSecure client;
InstagramStats instaStats(client, INSTAGRAM_ACCESS_TOKEN, IG_USER_ID);

unsigned long delayBetweenChecks = 60000; //mean time between api requests
unsigned long whenDueToCheck = 0;

void setup() {

  Serial.begin(115200);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  //Set client insecure for https connections
  client.setInsecure();
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}

void getInstagramStatsForUser() {
  Serial.println("Getting instagram user stats for " + IG_USER_ID);
  int instaFollowersCount = instaStats.getFollowersCount(IG_USER_ID);
  Serial.println("Response:");
  Serial.print("Number of followers: ");
  Serial.println(instaFollowersCount);
}

void loop() {
  unsigned long timeNow = millis();
  if ((timeNow > whenDueToCheck))  {
    getInstagramStatsForUser();
    whenDueToCheck = timeNow + delayBetweenChecks;
  }
}
