#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "ESPButton.h"
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>

extern "C" homekit_server_config_t config;

extern "C" void accessory_init();
extern "C" bool get_switch_status(int port);
extern "C" bool set_switch_status(int port, bool st);

#define PIN_BUTTON D5

static uint32_t next_heap_millis = 0;

int channel_status[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

WiFiManager wifiManager;

//----------------------------------
// Micro controller functions
//----------------------------------
void setup() {
  Serial.begin(115200);

  wifiManager.setConfigPortalTimeout(180);
  if(!wifiManager.autoConnect("Rancho P&R - Smart")) {
      printf("Failed to connect and hit timeout");
  }

  homekit_setup();
}

void loop() {
  homekit_loop();
}

//----------------------------------
// Homekit functions
//----------------------------------
void homekit_setup() {
  accessory_init();

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  
  ESPButton.add(0, PIN_BUTTON, LOW, true, true);
  
  ESPButton.setCallback([&](uint8_t id, ESPButtonEvent event) {
    printf("Button %d Event: %s\n", id, ESPButton.getButtonEventDescription(event));
    
    if (event == ESPBUTTONEVENT_LONGCLICK) {
      printf("Cleanning and rebooting...\n");
      wifiManager.resetSettings();
      homekit_storage_reset();
      ESP.restart();
    }
  });

  ESPButton.begin();

  arduino_homekit_setup(&config);
}

void homekit_loop() {
  ESPButton.loop();
  arduino_homekit_loop();
  const uint32_t t = millis();
  
  if (t > next_heap_millis) {
    // Show heap info every 10 seconds
    next_heap_millis = t + 10 * 1000;
    printf("Free heap: %d, HomeKit clients: %d\n",
        ESP.getFreeHeap(), arduino_homekit_connected_clients_count());
  }
}