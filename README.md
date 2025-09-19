# 🕹️ Leitura de Joystick Analógico com Raspberry Pi Pico
Um projeto simples e prático para interagir com um joystick analógico (módulo XY) usando o processador ARM Cortex-M0+ do Raspberry Pi Pico (RP2040). O código demonstra como ler os valores dos eixos X e Y usando o Conversor Analógico-Digital (ADC) e converter essa leitura em direções discretas (Cima, Baixo, Esquerda, Direita).

O projeto também inclui feedback visual através de LEDs e a impressão da direção detectada no monitor serial, tornando-o ideal para quem está começando com a leitura de periféricos analógicos.

### 🌟 Recursos
* ⚡ Leitura de Joystick Analógico: Utilize os canais ADC do RP2040 para ler os valores brutos dos eixos X e Y do joystick.
* 💬 Feedback Visual e Serial: O sistema acende LEDs e imprime a direção detectada (Esquerda, Direita, Cima, Baixo ou Centro) no console serial em tempo real.
* 🧩 Código Modular: O projeto é organizado em arquivos .h e .c (joystick.h e joystick.c) para facilitar a reutilização e a compreensão do código.
* 💡 Configuração Simples: O código é fácil de entender e adaptar, com constantes de pin e threshold claramente definidas.

### 🛠️ Pré-requisitos
* 🔩 Hardware
  *  Raspberry Pi Pico ou Pico W
  *  Módulo de Joystick Analógico XY
  *  LED da placa

* 💻 Software
  * Pico C/C++ SDK configurado.
  * ARM GCC Toolchain
  * CMake

### 🚀 Como Usar
* Clone o Repositório
  * ``git clone https://github.com/LabirasIFPI/bitdoglab_joystick.git ``

### 👨‍💻 Compile o Projeto

Navegue até o diretório do projeto e compile-o.

``mkdir build
cd build
cmake ..
make``

### ✨ Flashe o Pico

Pressione e segure o botão BOOTSEL no seu Pico e conecte-o ao computador.
Ele aparecerá como um dispositivo de armazenamento USB.
Arraste o arquivo .uf2 gerado na pasta build para dentro do Pico.

A placa irá reiniciar. Abra um monitor serial (como o minicom ou a extensão Serial Monitor do VS Code) para ver a direção do joystick em tempo real! 👀

### 🔬 Projeto Principal
O que faz: O programa lê continuamente a posição de um joystick analógico, acende um LED (LED_PIN_A ou LED_PIN_B) e exibe a direção no monitor serial.

Conceito: Demonstra o uso de ADC e GPIOs para interagir com periféricos externos e fornecer feedback em tempo real.

Explore a simplicidade de conectar periféricos ao seu Raspberry Pi Pico e comece a construir projetos interativos! 🌐

### 📄 Licença
Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
