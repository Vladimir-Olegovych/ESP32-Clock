#include <Arduino.h>
#include <Charset.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>

#include <string>
#include <stdio.h>
#include <time.h>

#define PIN 25
#define NUMPIXELS 256

const String serverName = "https://timeapi.io/api/time/current/zone";
const char* ssid = "realme GT6";
const char* password = "e8aa3fbq";

short getLamp(short x, short y);
void setTime(
  int hours, int minutes, int seconds, 
  int day, int mounth, int year
);
String httpRequestTime();

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
Charset charset = Charset();

void drawListener(int x, int y) {
    pixels.setPixelColor(getLamp(x, y), pixels.Color(255, 0, 255));
    pixels.show();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

  pixels.setBrightness(1);
  pixels.begin();
  charset.setListener(drawListener);
}

void loop() {
  String response = httpRequestTime();
  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, response);
  if (error) {
      Serial.println("Error - DeserializationError: ");
      Serial.print(error.f_str());
      return;
  }
  int hour = doc["hour"];
  int minute = doc["minute"];
  int seconds = doc["seconds"];

  int day = doc["day"];
  int month = doc["month"];
  int year = doc["year"];

  setTime(hour, minute, seconds, day, month, year);

  while (true)
  {
    char bufTime[80];
    char bufDay[80];
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    strftime(bufTime, sizeof(bufTime), "%H %M", &tstruct);
    strftime(bufDay, sizeof(bufDay), "%d.%m", &tstruct);

    pixels.clear();
    charset.drawText(0, 11, bufDay);
    charset.drawText(0, 0, bufTime);
    delay(60 * 1000);
  }
}
void setTime(
  int hours, int minutes, int seconds, 
  int day, int mounth, int year
) {
  struct timeval tv;
  struct tm newtime;

  newtime.tm_year = year - 1900;  // Год с 1900
  newtime.tm_mon = mounth - 1;        // Месяц от 0 до 11
  newtime.tm_mday = day;           // День
  newtime.tm_hour = hours;           // Часы
  newtime.tm_min = minutes;            // Минуты
  newtime.tm_sec = seconds + 5;             // Секунды

  tv.tv_sec = mktime(&newtime);
  tv.tv_usec = 0;
  settimeofday(&tv, nullptr);
}
String httpRequestTime(){
  if(WiFi.status()== WL_CONNECTED)
  {
    HTTPClient http;
    String serverPath = serverName + "?timeZone=Europe/Samara";
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());
    // Send HTTP GET request
    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0) 
    {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      return payload;
    } 
    else 
    {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      return "null";
    }
    http.end();
  } 
  else 
  {
    Serial.println("WiFi Disconnected");
    return "null";
  }
}

short getLamp(short x, short y){
  return y * 16 + (y % 2 == 0 ? x : 16 - x - 1);
}