#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#include "rgb_led.h"

#define BLINK_GPIO 2

void app_main(void)
{
    gpio_reset_pin(BLINK_GPIO);

    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1)
    {
        rgb_led_wifi_app_started();
        printf("Turning off the LED\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        printf("Turning on the LED\n");
        gpio_set_level(BLINK_GPIO, 1);
        rgb_led_wifi_connected();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}