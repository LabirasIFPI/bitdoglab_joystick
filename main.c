#include <stdio.h>
#include "pico/stdlib.h"
#include "joystick.h" // Inclui a interface do nosso módulo
#define LED_PIN_A 11
#define LED_PIN_B 13

int main() {
    stdio_init_all();
    sleep_ms(1000);

    // 1. Inicializa o hardware ADC para o joystick
    joystick_init();

    // Inicializa os pinos de LED para feedback visual
    gpio_init(LED_PIN_A);
    gpio_set_dir(LED_PIN_A, GPIO_OUT);
    gpio_init(LED_PIN_B);
    gpio_set_dir(LED_PIN_B, GPIO_OUT);

    printf("Sistema de Leitura de Joystick Iniciado.\\n");

    while (true) {
        // 2. Obtém a direção atual do joystick
        JoystickDirection dir = joystick_get_direction();

        // 3. Age com base na direção
        switch (dir) {
            case JOYSTICK_LEFT:
                printf("Esquerda\\n");
                gpio_put(LED_PIN_A, 1);
                break;
            case JOYSTICK_RIGHT:
                printf("Direita\\n");
                gpio_put(LED_PIN_B, 1);
                break;
            case JOYSTICK_DOWN:
                printf("Baixo\\n");
                gpio_put(LED_PIN_A, 1);
                break;
            case JOYSTICK_UP:
                printf("Cima\\n");
                gpio_put(LED_PIN_B, 1);
                break;
            case JOYSTICK_CENTER:
                // Nenhuma ação quando centralizado
                break;
        }

        sleep_ms(100); // Pausa para não sobrecarregar o console
        
        // Desliga os LEDs após a leitura
        gpio_put(LED_PIN_A, 0);
        gpio_put(LED_PIN_B, 0);
    }
    return 0;
}