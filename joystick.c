#include "joystick.h"

void joystick_init() {
    // Inicializa o periférico ADC
    adc_init();

    // Habilita os pinos GPIO para leitura analógica
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);
}

JoystickDirection joystick_get_direction() {
    // Lê o valor bruto do Eixo X (ADC 0)
    adc_select_input(0);
    uint16_t adc_x_raw = adc_read();

    // Lê o valor bruto do Eixo Y (ADC 1)
    adc_select_input(1);
    uint16_t adc_y_raw = adc_read();

    // Verifica a direção no Eixo X
    if (adc_x_raw < JOYSTICK_LOWER_THRESHOLD) {
        return JOYSTICK_LEFT;
    } else if (adc_x_raw > JOYSTICK_UPPER_THRESHOLD) {
        return JOYSTICK_RIGHT;
    }

    // Verifica a direção no Eixo Y
    if (adc_y_raw < JOYSTICK_LOWER_THRESHOLD) {
        return JOYSTICK_DOWN;
    } else if (adc_y_raw > JOYSTICK_UPPER_THRESHOLD) {
        return JOYSTICK_UP;
    }

    // Se nenhuma condição for atendida, está no centro
    return JOYSTICK_CENTER;
}