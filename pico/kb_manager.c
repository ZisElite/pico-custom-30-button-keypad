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
const uint32_t INIT_MASK = 0x203FFFC;
const uint32_t DIR_MASK = 0x2000000;
const uint32_t INPUT_PINS_MASK = 0x3FFFC;
const uint32_t BUTTONS_MASK = 0x3FFC;
const uint32_t ROW_1_MASK = 0x3C;
const uint32_t ROW_2_MASK = 0x3C0;
const uint32_t ROW_3_MASK = 0x3C00;
const uint32_t MODE_MASK =  0x3C000;

int main()
{
    bi_decl(bi_program_description("This is the keyboard manager binary."));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();

    gpio_init_mask(INIT_MASK);
    gpio_set_dir_masked(INIT_MASK, DIR_MASK);
    gpio_put(LED_PIN, 0);
    uint32_t input;
    uint32_t previous_input;
    uint row1, row1_old, row1_out, row2, row2_old, row2_out, row3, row3_old, row3_out, pins, pins_old, mode = 0;
    while(true)
    {
        input = gpio_get_all() & INPUT_PINS_MASK;
        pins = input & BUTTONS_MASK;
        if (pins)
        {
            gpio_put(LED_PIN, 1);
            // Get the button number for each row, 1-8 if one is pressed, 0 if none is pressed
            row1 = (input & ROW_1_MASK) >> 2;
            row2 = (input & ROW_2_MASK) >> 6;
            row3 = (input & ROW_3_MASK) >> 10;
            mode = (input & MODE_MASK) >> 14;
            // Check if the button is still pressed and increase its value by 10 if it is
            row1_out = (row1 == row1_old) && row1 != 0 ? row1 + 10 : row1;
            row2_out = (row2 == row2_old) && row2 != 0 ? row2 + 10 : row2;
            row3_out = (row3 == row3_old) && row3 != 0 ? row3 + 10 : row3;
            // Output the buttons along with the current mode
            printf("%lu, %lu, %lu, %lu\n", mode, row1_out, row2_out, row3_out);
            row1_old = row1;
            row2_old = row2;
            row3_old = row3;
            pins_old = pins;
        }
        else if (pins_old)
        {
            printf("unpressed\n");
            gpio_put(LED_PIN, 0);
            row1_old = 0;
            row2_old = 0;
            row3_old = 0;
            pins_old = 0;
        }
        sleep_ms(50);
    }
}