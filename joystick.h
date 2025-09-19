#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico/stdlib.h"
#include "hardware/adc.h"// --- Constantes para a Leitura do Joystick ---

// Define os pinos GPIO para os eixos X e Y
// GPIO26 é o canal 0 do ADC, GPIO27 é o canal 1
#define JOYSTICK_X_PIN 26
#define JOYSTICK_Y_PIN 27

// Limites (Thresholds) para detecção de movimento.
// Valores de ADC brutos (0-4095). Calibre conforme seu joystick.
#define JOYSTICK_LOWER_THRESHOLD 1000
#define JOYSTICK_UPPER_THRESHOLD 3000

// Enumeração para representar as direções de forma clara
typedef enum {
    JOYSTICK_CENTER,
    JOYSTICK_UP,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT
} JoystickDirection;

// --- Protótipos das Funções ---

/**
 * @brief Inicializa o hardware ADC e os pinos GPIO para o joystick.
 */
void joystick_init();

/**
 * @brief Lê os valores dos eixos X e Y e retorna a direção correspondente.
 * * @return Um valor da enumeração JoystickDirection (UP, DOWN, LEFT, RIGHT, CENTER).
 */
JoystickDirection joystick_get_direction();

#endif // JOYSTICK_H