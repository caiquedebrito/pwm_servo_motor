#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // Definição do pino PWM para o servo
#define PWM_FREQ 50   // Frequência de 50Hz (Período de 20ms)
#define PWM_WRAP 20000 // Contagem total do PWM (20ms em microsegundos)

static const int WAIT_MS = 5000; // Tempo de espera em milissegundos

// Função para configurar o PWM
void setup_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM); // Configura o pino como saída PWM
    uint slice_num = pwm_gpio_to_slice_num(pin); // Obtém o número do slice PWM
    pwm_set_wrap(slice_num, PWM_WRAP); // Define o período do PWM para 20ms
    pwm_set_clkdiv(slice_num, 125.0f); // Configuração do divisor de clock para atingir 50Hz
    pwm_set_enabled(slice_num, true); // Habilita o PWM
}

// Função para definir o ciclo ativo (duty cycle) do servo em microssegundos
void set_servo_position(uint pin, uint pulse_width) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, pulse_width); // Define o nível PWM
}

// Função para movimentação suave do servo entre 0° e 180°
void smooth_movement(uint pin, uint start, uint end, int step, int delay_ms) {
    if (start > end) step = -step; // Define o passo negativo se estiver diminuindo

    for (uint pulse = start; (step > 0) ? (pulse <= end) : (pulse >= end); pulse += step) {
        set_servo_position(pin, pulse);
        sleep_ms(delay_ms); // Aguarda para suavizar o movimento
    }
}

int main() {
    stdio_init_all(); // Inicializa a comunicação padrão
    setup_pwm(SERVO_PIN); // Configura o PWM na GPIO 22

    // Posição 180° (2400µs)
    set_servo_position(SERVO_PIN, 2400);
    sleep_ms(WAIT_MS);

    // Posição 90° (1470µs)
    set_servo_position(SERVO_PIN, 1470);
    sleep_ms(WAIT_MS);

    // Posição 0° (500µs)
    set_servo_position(SERVO_PIN, 500);
    sleep_ms(WAIT_MS);

    // Movimento suave entre 0° e 180° com incremento de 5µs a cada 10ms
    while (1) {
        smooth_movement(SERVO_PIN, 500, 2400, 5, 10);
        smooth_movement(SERVO_PIN, 2400, 500, 5, 10);
    }

    return 0;
}
