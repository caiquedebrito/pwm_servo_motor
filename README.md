# Controle Servomotor por PWM

![Image](https://github.com/user-attachments/assets/3320ea97-6982-4dde-afbc-9d603654cda6)

## Apresentação dos resultados

[Vídeo no Youtube](https://youtu.be/jVGhoxXRAHY)

## Estrutura do projeto

- ``CMakeLists.txt``: arquivo para o build do projeto
- ``diagram.json`` e ``wokwi.toml``: arquivos para execução do simulador wokwi
- ``pwm_servomotor.c``: arquivo principal para a execução do projeto

## Componentes utilizados

1. Microcontrolador Raspberry Pi Pico W. 
2. Servomotor - motor micro servo padrão - Wokwi.
3. Kit BitDogLab
4. LED RGB

## Compilação e Execução do Projeto

### Pré-requisitos

Antes de começar, certifique-se de ter instalado:

- Visual Studio Code
- Extensões do VS Code:
  - CMake Tools
  - Wokwi for VS Code
- CMake
- GCC ARM (para compilar código para microcontroladores)

### Configuração do Projeto

1. Clone o repositório
```bash
git clone https://github.com/caiqudebrito/pwm_servo_motor.git
cd pwm_servo_motor
```

2. Configure o CMake
No VS Code, abra o projeto e selecione a ferramenta de compilação:

- Pressione `Ctrl + Shift + P` e busque por **CMake: Configure**.
- Escolha o kit de compilação (exemplo: **GCC ARM Embedded**).

3. Compile o código
- No terminal, execute:
``` bash
cmake --build build
```
- Ou, no VS Code, clique em **Build** na barra de status do CMake.

### Executando no Wokwi
1. Abra o simulador

- Pressione `Ctrl + Shift + P` e busque por **Wokwi: Start Simulation**.
- Selecione o arquivo `wokwi.toml` na raiz do projeto.

2. Teste e depure

- Use a interface gráfica do Wokwi para interagir com os componentes.
- Caso precise depurar, ative logs no código-fonte e utilize a saída serial.


## Requisitos da atividade implementados

1) Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms. (20% da nota) 
2) Defina o ciclo ativo do módulo PWM para 2.400µs 
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta 
posição. (10% da nota) 
3) Defina o ciclo ativo do módulo PWM para 1.470µs 
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição. (10% da nota) 
4) Defina o ciclo ativo do módulo PWM para 500µs 
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta 
posição. (10% da nota) 
5) Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.  Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, 
com um atraso de ajuste de 10ms. (35% da nota) 
6) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12. O que o discente observou no comportamento da iluminação do referido LED? (15% da nota) 
