#include <Arduino.h>
#include <homekit/types.h>
#include <homekit/homekit.h>
#include <homekit/characteristics.h>
#include <stdio.h>
#include <port.h>

#define PIN_LED_BUILD_IN 16  // Build in LED

bool bulbs_status[16]     = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; 

bool get_switch_status(int port) {
  if(port <= 15) {
    return bulbs_status[port];  
  } else {
    printf("get_switch_status port is invalid: %d\n", port);
    return false;
  }
}

void set_status(int port, bool st) {
  bulbs_status[port] = st;
}



//-------------------------------------------------------------------
// Bulb 1
//-------------------------------------------------------------------

void switch_1_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(0, value.bool_value); 
}

homekit_value_t switch_1_on_get() {
  return HOMEKIT_BOOL(get_switch_status(0));
}

homekit_characteristic_t switch_1_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_1_on_get,
  .setter=switch_1_on_set
);

//-------------------------------------------------------------------
// END Switch 1
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 2
//-------------------------------------------------------------------

void switch_2_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(1, value.bool_value); 
}

homekit_value_t switch_2_on_get() {
  return HOMEKIT_BOOL(get_switch_status(1));
}

homekit_characteristic_t switch_2_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_2_on_get,
  .setter=switch_2_on_set
);

//-------------------------------------------------------------------
// END Switch 2
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 3
//-------------------------------------------------------------------

void switch_3_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(2, value.bool_value); 
}

homekit_value_t switch_3_on_get() {
  return HOMEKIT_BOOL(get_switch_status(2));
}

homekit_characteristic_t switch_3_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_3_on_get,
  .setter=switch_3_on_set
);

//-------------------------------------------------------------------
// END Switch 3
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 4
//-------------------------------------------------------------------

void switch_4_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(3, value.bool_value); 
}

homekit_value_t switch_4_on_get() {
  return HOMEKIT_BOOL(get_switch_status(3));
}

homekit_characteristic_t switch_4_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_4_on_get,
  .setter=switch_4_on_set
);

//-------------------------------------------------------------------
// END Switch 4
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 5
//-------------------------------------------------------------------

void switch_5_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(4, value.bool_value); 
}

homekit_value_t switch_5_on_get() {
  return HOMEKIT_BOOL(get_switch_status(4));
}

homekit_characteristic_t switch_5_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_5_on_get,
  .setter=switch_5_on_set
);

//-------------------------------------------------------------------
// END Switch 5
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 6
//-------------------------------------------------------------------

void switch_6_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(5, value.bool_value); 
}

homekit_value_t switch_6_on_get() {
  return HOMEKIT_BOOL(get_switch_status(5));
}

homekit_characteristic_t switch_6_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_6_on_get,
  .setter=switch_6_on_set
);

//-------------------------------------------------------------------
// END Switch 6
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 7
//-------------------------------------------------------------------

void switch_7_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(6, value.bool_value); 
}

homekit_value_t switch_7_on_get() {
  return HOMEKIT_BOOL(get_switch_status(6));
}

homekit_characteristic_t switch_7_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_7_on_get,
  .setter=switch_7_on_set
);

//-------------------------------------------------------------------
// END Switch 7
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 8
//-------------------------------------------------------------------

void switch_8_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(7, value.bool_value); 
}

homekit_value_t switch_8_on_get() {
  return HOMEKIT_BOOL(get_switch_status(7));
}

homekit_characteristic_t switch_8_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_8_on_get,
  .setter=switch_8_on_set
);

//-------------------------------------------------------------------
// END Switch 8
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 9
//-------------------------------------------------------------------

void switch_9_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(8, value.bool_value); 
}

homekit_value_t switch_9_on_get() {
  return HOMEKIT_BOOL(get_switch_status(8));
}

homekit_characteristic_t switch_9_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_9_on_get,
  .setter=switch_9_on_set
);

//-------------------------------------------------------------------
// END Switch 9
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 10
//-------------------------------------------------------------------

void switch_10_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(9, value.bool_value); 
}

homekit_value_t switch_10_on_get() {
  return HOMEKIT_BOOL(get_switch_status(9));
}

homekit_characteristic_t switch_10_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_10_on_get,
  .setter=switch_10_on_set
);

//-------------------------------------------------------------------
// END Switch 10
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 11
//-------------------------------------------------------------------

void switch_11_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(10, value.bool_value); 
}

homekit_value_t switch_11_on_get() {
  return HOMEKIT_BOOL(get_switch_status(10));
}

homekit_characteristic_t switch_11_status = HOMEKIT_CHARACTERISTIC_(ON, false,
  .getter=switch_11_on_get,
  .setter=switch_11_on_set
);

//-------------------------------------------------------------------
// END Switch 11
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 12
//-------------------------------------------------------------------

void switch_12_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(11, value.bool_value); 
}

homekit_value_t switch_12_on_get() {
  return HOMEKIT_BOOL(get_switch_status(11));
}

homekit_characteristic_t switch_12_status = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false,
  .getter=switch_12_on_get,
  .setter=switch_12_on_set
);

//-------------------------------------------------------------------
// END Switch 12
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 13
//-------------------------------------------------------------------

void switch_13_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(12, value.bool_value); 
}

homekit_value_t switch_13_on_get() {
  return HOMEKIT_BOOL(get_switch_status(12));
}

homekit_characteristic_t switch_13_status = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false,
  .getter=switch_13_on_get,
  .setter=switch_13_on_set
);

//-------------------------------------------------------------------
// END Switch 13
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 14
//-------------------------------------------------------------------

void switch_14_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(13, value.bool_value); 
}

homekit_value_t switch_14_on_get() {
  return HOMEKIT_BOOL(get_switch_status(13));
}

homekit_characteristic_t switch_14_status = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false,
  .getter=switch_14_on_get,
  .setter=switch_14_on_set
);

//-------------------------------------------------------------------
// END Switch 14
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 15
//-------------------------------------------------------------------

void switch_15_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(14, value.bool_value); 
}

homekit_value_t switch_15_on_get() {
  return HOMEKIT_BOOL(get_switch_status(14));
}

homekit_characteristic_t switch_15_status = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false,
  .getter=switch_15_on_get,
  .setter=switch_15_on_set
);

//-------------------------------------------------------------------
// END Switch 15
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Bulb 16
//-------------------------------------------------------------------

void switch_16_on_set(homekit_value_t value) {
  if (value.format != homekit_format_bool) {
    printf("Invalid on-value format: %d\n", value.format);
    return;
  }
  set_status(15, value.bool_value); 
}

homekit_value_t switch_16_on_get() {
  return HOMEKIT_BOOL(get_switch_status(15));
}

homekit_characteristic_t switch_16_status = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false,
  .getter=switch_16_on_get,
  .setter=switch_16_on_set
);

//-------------------------------------------------------------------
// END Switch 16
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
            HOMEKIT_CHARACTERISTIC(NAME, "Smart 16 Channels Switcher"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Rancho P&R Smart Experience by fabiotomio"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "7890000000003"),
            HOMEKIT_CHARACTERISTIC(MODEL, "16 channels switcher"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=2, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 1"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_1_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 1"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=3, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 2"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_2_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 2"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=4, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 3"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_3_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 3"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=5, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 4"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_4_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 4"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=6, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 5"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 5"),
            &switch_5_status,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=7, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 6"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 6"),
            &switch_6_status,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=8, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 7"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 7"),
            &switch_7_status,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=9, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 8"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 8"),
            &switch_8_status,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=10, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 8"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 9"),
            &switch_9_status,
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=11, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 10"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_10_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 10"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=12, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 11"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_11_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Switch 11"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=13, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 12"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_12_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor 1"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=14, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 13"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_13_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor 2"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=15, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 14"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_14_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor 3"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=16, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 15"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_15_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor 4"),
            NULL
        }),
        NULL
    }),
    HOMEKIT_ACCESSORY(.id=17, .category=homekit_accessory_category_lightbulb, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switcher Channel 16"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &switch_16_status,
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor 5"),
            NULL
        }),
        NULL
    }),
    NULL
};

homekit_server_config_t config = {
    .accessories = accessories,
    .password = "461-33-123",
    .setupId = "ABCD"
};
