#include <Arduino.h>
#include <homekit/types.h>
#include <homekit/homekit.h>
#include <homekit/characteristics.h>
#include <stdio.h>
#include <port.h>

#define PIN_LED_BUILD_IN 16  // Build in LED

const int pwm_brightness[11] = {0, 40, 80, 120, 200, 400, 500, 1000, 2000, 3000, 4095}; 

bool bulbs_status[16]     = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; 
int  bulbs_brightness[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int  bulbs_pwm[16]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


bool get_bulb_status(int port) {
  if(port <= 15) {
    return bulbs_status[port];  
  } else {
    printf("get_bulb_status port is invalid: %d\n", port);
    return false;
  }
}

int get_bulb_brightness(int port) {
  if(port <= 15) {
    return bulbs_brightness[port];  
  } else {
    printf("get_bulb_brightness port is invalid: %d\n", port);
    return 0;
  }
}

int get_bulb_pwm(int port) {
  return bulbs_pwm[port];
}

void set_status(int port, bool st) {
  bulbs_status[port] = st;
}

void set_brightness(int port, int brightness) {
  bulbs_brightness[port] = brightness;

  const int pwm_index = brightness / 10;
  const int pwm = pwm_brightness[pwm_index];
  const int pwm_range = (pwm_brightness[pwm_index + 1] - 1 - pwm) / 9;

  bulbs_pwm[port] = pwm + ((brightness % 10) * pwm_range );
}




//-------------------------------------------------------------------
// Bulb 1
//-------------------------------------------------------------------

void bulb_1_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(0, value.bool_value); 
}

homekit_value_t bulb_1_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(0));
}

void switch_1_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(0, value.int_value);
}

homekit_value_t bulb_1_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(0));
}

homekit_characteristic_t bulb_1_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_1_on_get,
  .setter=bulb_1_on_set
);

homekit_characteristic_t bulb_1_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_1_brightness_get,
  .setter=switch_1_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 1
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 2
//-------------------------------------------------------------------

void bulb_2_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(1, value.bool_value); 
}

homekit_value_t bulb_2_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(1));
}

void switch_2_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(1, value.int_value);
}

homekit_value_t bulb_2_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(1));
}

homekit_characteristic_t bulb_2_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_2_on_get,
  .setter=bulb_2_on_set
);

homekit_characteristic_t bulb_2_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_2_brightness_get,
  .setter=switch_2_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 2
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 3
//-------------------------------------------------------------------

void bulb_3_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(2, value.bool_value); 
}

homekit_value_t bulb_3_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(2));
}

void switch_3_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(2, value.int_value);
}

homekit_value_t bulb_3_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(2));
}

homekit_characteristic_t bulb_3_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_3_on_get,
  .setter=bulb_3_on_set
);

homekit_characteristic_t bulb_3_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_3_brightness_get,
  .setter=switch_3_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 3
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 4
//-------------------------------------------------------------------

void bulb_4_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(3, value.bool_value); 
}

homekit_value_t bulb_4_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(3));
}

void switch_4_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(3, value.int_value);
}

homekit_value_t bulb_4_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(3));
}

homekit_characteristic_t bulb_4_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_4_on_get,
  .setter=bulb_4_on_set
);

homekit_characteristic_t bulb_4_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_4_brightness_get,
  .setter=switch_4_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 4
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 5
//-------------------------------------------------------------------

void bulb_5_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(4, value.bool_value); 
}

homekit_value_t bulb_5_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(4));
}

void switch_5_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(4, value.int_value);
}

homekit_value_t bulb_5_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(4));
}

homekit_characteristic_t bulb_5_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_5_on_get,
  .setter=bulb_5_on_set
);

homekit_characteristic_t bulb_5_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_5_brightness_get,
  .setter=switch_5_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 5
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 6
//-------------------------------------------------------------------

void bulb_6_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(5, value.bool_value); 
}

homekit_value_t bulb_6_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(5));
}

void switch_6_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(5, value.int_value);
}

homekit_value_t bulb_6_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(5));
}

homekit_characteristic_t bulb_6_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_6_on_get,
  .setter=bulb_6_on_set
);

homekit_characteristic_t bulb_6_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_6_brightness_get,
  .setter=switch_6_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 6
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 7
//-------------------------------------------------------------------

void bulb_7_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(6, value.bool_value); 
}

homekit_value_t bulb_7_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(6));
}

void switch_7_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(6, value.int_value);
}

homekit_value_t bulb_7_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(6));
}

homekit_characteristic_t bulb_7_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_7_on_get,
  .setter=bulb_7_on_set
);

homekit_characteristic_t bulb_7_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_7_brightness_get,
  .setter=switch_7_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 7
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 8
//-------------------------------------------------------------------

void bulb_8_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(7, value.bool_value); 
}

homekit_value_t bulb_8_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(7));
}

void switch_8_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(7, value.int_value);
}

homekit_value_t bulb_8_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(7));
}

homekit_characteristic_t bulb_8_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_8_on_get,
  .setter=bulb_8_on_set
);

homekit_characteristic_t bulb_8_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_8_brightness_get,
  .setter=switch_8_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 8
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 9
//-------------------------------------------------------------------

void bulb_9_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(8, value.bool_value); 
}

homekit_value_t bulb_9_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(8));
}

void switch_9_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(8, value.int_value);
}

homekit_value_t bulb_9_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(8));
}

homekit_characteristic_t bulb_9_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_9_on_get,
  .setter=bulb_9_on_set
);

homekit_characteristic_t bulb_9_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_9_brightness_get,
  .setter=switch_9_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 9
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 10
//-------------------------------------------------------------------

void bulb_10_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(9, value.bool_value); 
}

homekit_value_t bulb_10_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(9));
}

void switch_10_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(9, value.int_value);
}

homekit_value_t bulb_10_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(9));
}

homekit_characteristic_t bulb_10_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_10_on_get,
  .setter=bulb_10_on_set
);

homekit_characteristic_t bulb_10_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_10_brightness_get,
  .setter=switch_10_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 10
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 11
//-------------------------------------------------------------------

void bulb_11_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(10, value.bool_value); 
}

homekit_value_t bulb_11_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(10));
}

void switch_11_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(10, value.int_value);
}

homekit_value_t bulb_11_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(10));
}

homekit_characteristic_t bulb_11_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_11_on_get,
  .setter=bulb_11_on_set
);

homekit_characteristic_t bulb_11_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_11_brightness_get,
  .setter=switch_11_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 11
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 12
//-------------------------------------------------------------------

void bulb_12_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(11, value.bool_value); 
}

homekit_value_t bulb_12_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(11));
}

void switch_12_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(11, value.int_value);
}

homekit_value_t bulb_12_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(11));
}

homekit_characteristic_t bulb_12_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_12_on_get,
  .setter=bulb_12_on_set
);

homekit_characteristic_t bulb_12_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_12_brightness_get,
  .setter=switch_12_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 12
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 13
//-------------------------------------------------------------------

void bulb_13_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(12, value.bool_value); 
}

homekit_value_t bulb_13_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(12));
}

void switch_13_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(12, value.int_value);
}

homekit_value_t bulb_13_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(12));
}

homekit_characteristic_t bulb_13_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_13_on_get,
  .setter=bulb_13_on_set
);

homekit_characteristic_t bulb_13_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_13_brightness_get,
  .setter=switch_13_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 13
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 14
//-------------------------------------------------------------------

void bulb_14_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(13, value.bool_value); 
}

homekit_value_t bulb_14_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(13));
}

void switch_14_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(13, value.int_value);
}

homekit_value_t bulb_14_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(13));
}

homekit_characteristic_t bulb_14_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_14_on_get,
  .setter=bulb_14_on_set
);

homekit_characteristic_t bulb_14_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_14_brightness_get,
  .setter=switch_14_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 14
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 15
//-------------------------------------------------------------------

void bulb_15_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(14, value.bool_value); 
}

homekit_value_t bulb_15_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(14));
}

void switch_15_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(14, value.int_value);
}

homekit_value_t bulb_15_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(14));
}

homekit_characteristic_t bulb_15_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_15_on_get,
  .setter=bulb_15_on_set
);

homekit_characteristic_t bulb_15_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_15_brightness_get,
  .setter=switch_15_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 15
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 16
//-------------------------------------------------------------------

void bulb_16_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(15, value.bool_value); 
}

homekit_value_t bulb_16_on_get() {
  return HOMEKIT_BOOL(get_bulb_status(15));
}

void switch_16_brightness_set(homekit_value_t value) {
  if (value.format != homekit_format_int) {
    return;
  }
  set_brightness(15, value.int_value);
}

homekit_value_t bulb_16_brightness_get() {
  return HOMEKIT_INT(get_bulb_brightness(15));
}

homekit_characteristic_t bulb_16_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=bulb_16_on_get,
  .setter=bulb_16_on_set
);

homekit_characteristic_t bulb_16_brightness = HOMEKIT_CHARACTERISTIC_(BRIGHTNESS, 0,
  .getter=bulb_16_brightness_get,
  .setter=switch_16_brightness_set
);

//-------------------------------------------------------------------
// END Bulb 16
//-------------------------------------------------------------------

















void accessory_init() {  
}

void builtInLed_set_status(bool on) {
  digitalWrite(PIN_LED_BUILD_IN, on ? LOW : HIGH);
}

void builtInLed_blink(int intervalInMs, int count) {
  for (int i = 0; i < count; i++) {
    builtInLed_set_status(true);
    delay(intervalInMs);
    builtInLed_set_status(false);
    delay(intervalInMs);
  }
}

void accessory_identify(homekit_value_t _value) {
  printf("accessory identify\n");
  builtInLed_blink(500, 3);
}

// Accessories

homekit_accessory_t *accessories[] = {
    HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_switch, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart 16 Channels LED Controller"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Rancho P&R Smart Experience by fabiotomio"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "7890000000002"),
            HOMEKIT_CHARACTERISTIC(MODEL, "16 channels"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=2, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 1"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_1_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 1"),
            &bulb_1_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=3, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 2"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_2_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 2"),
            &bulb_2_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=4, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 3"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_3_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 3"),
            &bulb_3_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=5, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 4"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_4_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 4"),
            &bulb_4_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=6, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 5"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 5"),
            &bulb_5_status,
            &bulb_5_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=7, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 6"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 6"),
            &bulb_6_status,
            &bulb_6_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=8, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 7"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 7"),
            &bulb_7_status,
            &bulb_7_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=9, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 8"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 8"),
            &bulb_8_status,
            &bulb_8_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=10, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 8"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 9"),
            &bulb_9_status,
            &bulb_9_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=11, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 10"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_10_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 10"),
            &bulb_10_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=12, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 11"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_11_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 11"),
            &bulb_11_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=13, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 12"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_12_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 12"),
            &bulb_12_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=14, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 13"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_13_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 13"),
            &bulb_13_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=15, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 14"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_14_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 14"),
            &bulb_14_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=16, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 15"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_15_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 15"),
            &bulb_15_brightness,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=17, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Smart Bulb Channel 16"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(LIGHTBULB, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &bulb_16_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Bulb 16"),
            &bulb_16_brightness,
            NULL
        }),
        NULL
    }),
    NULL
};

homekit_server_config_t config = {
    .accessories = accessories,
    .password = "461-33-000",
    .setupId = "ABCD"
};
