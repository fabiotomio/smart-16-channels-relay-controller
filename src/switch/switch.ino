#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "ESPButton.h"
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <Adafruit_PWMServoDriver.h>

extern "C" homekit_server_config_t config;

extern "C" void accessory_init();
extern "C" bool get_bulb_status(int port);
extern "C" int get_bulb_brightness(int port);
extern "C" int get_bulb_pwm(int port);

#define PIN_BUTTON D5

// Wifi configs
#ifndef STASSID
#define STASSID "Rancho P&R - Gerânio"
#define STAPSK  "ranchoper"
#endif

const int pwm_update_interval = 25;
const char* ssid     = STASSID;
const char* password = STAPSK;
uint8_t newMACAddress[] = {0x12, 0x0E, 0xA4, 0x37, 0x0D, 0x66};

uint32_t next_pwd_millis = 0;
uint32_t next_heap_millis = 0;

int channel_pwm[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Adafruit_PWMServoDriver pwm_driver = Adafruit_PWMServoDriver();

//----------------------------------
// Micro controller functions
//----------------------------------
void setup() {
	Serial.begin(115200);

  wifi_set_macaddr(STATION_IF, &newMACAddress[0]);
	wifi_connect();

  pwm_driver.begin();
  pwm_driver.setPWMFreq(600);

  for(int i=0; i<=15; i++) {
    update_pwd_port(i);
  }

	homekit_setup();
}

void loop() {
  wifi_loop();
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
}

void update_pwd_output(int port) {
  const int port_pwm = channel_pwm[port];
  int bulb_pwd = get_bulb_pwm(port);

  if(get_bulb_status(port) == false) {
    bulb_pwd = 0;
  }

  if(port_pwm == bulb_pwd) {
    return;
  }

  channel_pwm[port] = bulb_pwd;
  update_pwd_port(port);
}

void update_pwd_port(int port) {
  Serial.print("Setting brightness port ");
  Serial.print(port);
  Serial.print(" to ");
  Serial.println(channel_pwm[port]);
  pwm_driver.setPWM(port, 0, channel_pwm[port]);
}

//----------------------------------
// Wifi functions
//----------------------------------
void wifi_loop() {
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi is disconnected!");
    wifi_connect();
  }
}

void wifi_connect() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
