#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

// const uint PIN_1 = 2;
// const uint PIN_2 = 3;
// const uint PIN_3 = 4;
// const uint PIN_4 = 5;
// const uint PIN_5 = 6;
// const uint PIN_6 =7;
// const uint PIN_7 =8;
// const uint PIN_8 =9;
// const uint PIN_9 = 10;
// const uint PIN_10 = 11;
// const uint PIN_11 = 12;
// const uint PIN_12 = 13;
// const uint MODE_1 = 14;
// const uint MODE_2 = 15;
// const uint MODE_3 = 16;
// const uint MODE_4 = 17;
const uint LED_PIN = 25;
const uint32_t ALL_PINS_MASK = 0x3fffc;
const uint32_t INPUT_PINS_MASK = 0x3FFC;
const uint32_t ROW_1_MASK = 0x3C;
const uint32_t ROW_2_MASK = 0x3C0;
const uint32_t ROW_3_MASK = 0x3C00;
const uint32_t MODE_MASK =  0x3C000;

int main()
{
    bi_decl(bi_program_description("This is the keyboard manager binary."));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);
    gpio_init_mask(ALL_PINS_MASK);
    gpio_set_dir_masked(ALL_PINS_MASK, 0);
    uint32_t input;
    uint32_t previous_input;
    uint row1, row2, row3, pins, mode = 0;
    gpio_put(LED_PIN, 1);
    while(true)
    {
        input = gpio_get_all() & ALL_PINS_MASK;
        pins = input & INPUT_PINS_MASK;
        row1 = (input & ROW_1_MASK) >> 2;
        row2 = (input & ROW_2_MASK) >> 6;
        row3 = (input & ROW_3_MASK) >> 10;
        mode = (input & MODE_MASK) >> 14;
        if (pins && input != previous_input)
        {
            gpio_put(LED_PIN, 1);
            printf("%lu, %lu, %lu, %lu\n", mode, row1, row2, row3);
        }
        else if (pins && previous_input == input)
        {
            gpio_put(LED_PIN, 1);
        }
        else
        {
            gpio_put(LED_PIN, 0);
        }
        previous_input = input;
        sleep_ms(50);
    }
}