# Smart 16 channels led controller

## 2021/12/21
- Adicionado suporte ao PCA9685 para adiciona o suporte a 16 portas PWM


## 2021/04/14
- O nome do acessório (HOMEKIT_CHARACTERISTIC(NAME,...) precisa ser diferente para o pareamento funcionar.
- O ID dos acessório (HOMEKIT_ACCESSORY(.id=1,..) precisa ser incremental sequencial.
- O pino Flash, é para gerenciar o acesso ao flash do ESP, não consegui utilizar como OUTPUT.
- O mesmo MAC Address faz com que o DHCP Server entregue o mesmo IP para o dispositivo.

# ESP8266 Arduino HomeKit Switch Controller

> Using an ESP8266 as a 16 channels led controller with native Apple HomeKit support

## Start/Setup

### Initial

Configure your wifi credentials in switch.ino, build and updload to EPS8266 board.

```diff
// accessory.c
homekit_server_config_t config = {
    .accessories = accessories,
-    .password = "111-11-111",
+    .password = "123-45-678",
    .setupId = "ABCD"
};
```

### Add to HomeKit

As soon as the ESP8266 is connected to the network, the `Home` app can be opened on the iOS device and be added as a new device.

#### Paring Code

For the paring enter the code: `461-33-000`.

## Workspace

### Local Development

#### Required

- Arduino v1.8.13
  - Additional Board Manager: `https://arduino.esp8266.com/stable/package_esp8266com_index.json`
    - esp8266 by ESP8266 Community: https://github.com/esp8266/Arduino
  - Libraries:
    - HomeKit-ESP8266 by Mixiaoxiao: `https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266`
- Python 3.9
  - pip `curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py`
    - esptool v3.0 `pip install esptool`
    - pyserial v3.5: `pip install pyserial`

## Author

**Fábio Tomio**

- Github: [@fabiotomio](https://github.com/fabiotomio)

## License

This project is [MIT](https://github.com/simongolms/arduino-homekit-esp8266-switch/blob/master/LICENSE) licensed.

## Resources

- [Arduino Board - ESP8266](https://www.esp8266.com/)
- [Arduino Library - Arduino-HomeKit-ESP8266](https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266)
- [Adafruit PWM](https://learn.adafruit.com/16-channel-pwm-servo-driver/library-reference)
- [Millis (without delay)]()https://randomnerdtutorials.com/interrupts-timers-esp8266-arduino-ide-nodemcu/)
- [Schema](https://diyi0t.com/wp-content/uploads/2020/11/Servo-PCA9685-ESP8266-NodeMCU_Steckplatine.png)
