#pragma     once
#ifndef _ARDUINO_STM32_H_
#define _ARDUINO_STM32_H_
// this is an arduino platform, so include the Arduino.h header file
#include <Arduino.h>

// For smt32 using arduino, just use arduino definition
#define fasEnableInterrupts interrupts
#define fasDisableInterrupts noInterrupts


#error "TO BE REVIEWED: This file below this point is not yet implemented for STM32."

#define SUPPORT_STM32
#define SUPPORT_EXTERNAL_DIRECTION_PIN
#define SUPPORT_UNSAFE_ABS_SPEED_LIMIT_SETTING 1



// Esp32 queue definitions
#define NUM_QUEUES (QUEUES_MCPWM_PCNT + QUEUES_RMT)
#define MAX_STEPPER (NUM_QUEUES)
#define QUEUE_LEN 32

// Esp32 timing definition
#define TICKS_PER_S 16000000L
#define MIN_CMD_TICKS (TICKS_PER_S / 5000)
#define MIN_DIR_DELAY_US (MIN_CMD_TICKS / (TICKS_PER_S / 1000000))
#define MAX_DIR_DELAY_US (65535 / (TICKS_PER_S / 1000000))
#define DELAY_MS_BASE 4

#define SUPPORT_QUEUE_ENTRY_START_POS_U16

// debug led timing
#define DEBUG_LED_HALF_PERIOD 50

#define noop_or_wait vTaskDelay(1)

// have more than one core
#define SUPPORT_CPU_AFFINITY

// have adjustable stepper task rate
#define SUPPORT_TASK_RATE_CHANGE

#define LL_TOGGLE_PIN(dirPin)                  \
  gpio_ll_set_level(&GPIO, (gpio_num_t)dirPin, \
                    gpio_ll_get_level(&GPIO, (gpio_num_t)dirPin) ^ 1)


#endif /* _ARDUINO_STM32_H_ */