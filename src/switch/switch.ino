#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "ESPButton.h"
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <Adafruit_PWMServoDriver.h>
#include <WiFiManager.h>

extern "C" homekit_server_config_t config;

extern "C" void accessory_init();
extern "C" bool get_bulb_status(int port);
extern "C" int get_bulb_brightness(int port);
extern "C" int get_bulb_pwm(int port);

#define PIN_BUTTON D5

const int pwm_update_interval = 1;

uint32_t next_pwd_millis = 0;
uint32_t next_pwd_log_millis = 0;
uint32_t next_heap_millis = 0;

int channel_pwm[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

WiFiManager wifiManager;
Adafruit_PWMServoDriver pwm_driver = Adafruit_PWMServoDriver();

//----------------------------------
// Micro controller functions
//----------------------------------
void setup() {
  Serial.begin(115200);

  wifiManager.setConfigPortalTimeout(180);
  if(!wifiManager.autoConnect("Rancho P&R - Smart")) {
      printf("Failed to connect and hit timeout");
  } 

  pwm_driver.begin();
  pwm_driver.setPWMFreq(600);

  for(int i=0; i<=15; i++) {
    update_pwd_port(i, 0);
  }

  homekit_setup();
}

void loop() {
  homekit_loop();
  pwd_loop();
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

//----------------------------------
// PWD functions
//----------------------------------
void pwd_loop() {
  const uint32_t t = millis();

  if(t > next_pwd_millis) {
    next_pwd_millis = t + pwm_update_interval;
    for(int i=0; i<=15; i++) {
      update_pwd_output(i);
    }
  }

  if(t > next_pwd_log_millis) {
    // Show pwm info every 2 seconds
    next_pwd_log_millis = t + 2 * 1000;
    for(int i=0; i<=15; i++) {
        Serial.print("Port ");
        Serial.print(i);
        Serial.print(" pwm ");
        Serial.println(channel_pwm[i]);
    }
  }
}

void update_pwd_output(int port) {
  int port_pwm = channel_pwm[port];
  int bulb_pwd = get_bulb_pwm(port);

  // caso a porta esteja desligada
  if(get_bulb_status(port) == false) {

    // se já tiver apagada, não faz nada
    if(port_pwm == 0) {
      return;
    }

    // senão decrementa a intensidade
    if(port_pwm - 10 <= 0) {
        port_pwm = 0;
    } else {
        port_pwm = port_pwm - 10;
    }

  // caso esteja ligada
  } else {

    // se tiver na intensidade correta, não faz nada
    if(port_pwm == bulb_pwd) {
      return;
    }

    // caso não esteja, dimeriza
    if(port_pwm > bulb_pwd) {
      if(port_pwm - 10 <= 0) {
        port_pwm = 0;
      } else {
        port_pwm = port_pwm - 10;
      }
    } else {
      port_pwm++;
    }

  }



  channel_pwm[port] = port_pwm;
  update_pwd_port(port, port_pwm);
}

void update_pwd_port(int port, int pwd) {
  pwm_driver.setPWM(port, 0, pwd);
}
