### Descrição do Projeto: Carrinho de Controle Remoto via Bluetooth utilizando ESP32

#### Introdução:
Este projeto consiste no desenvolvimento de um carrinho de controle remoto controlado por um aplicativo Android via Bluetooth. O controle do carrinho é realizado através de comandos enviados ao ESP32, que interpreta os sinais Bluetooth e aciona os motores, possibilitando o movimento do carrinho para diferentes direções. O projeto tem como objetivo explorar a integração de hardware e software, usando uma ponte H para controlar motores de corrente contínua (DC) e o ESP32 como unidade central de processamento.

#### Componentes Utilizados:
1. **ESP32**: O microcontrolador central responsável por gerenciar a comunicação Bluetooth e o controle dos motores.
2. **Motores DC**: Dois motores de corrente contínua que proporcionam a movimentação do carrinho.
3. **Ponte H (L298N)**: Controlador de motor que permite acionar os motores em ambas as direções (para frente e para trás).
4. **Fonte de Alimentação**: Bateria para alimentar o sistema, incluindo motores e ESP32.
5. **Aplicativo "Arduino Bluetooth Control"**: Aplicativo disponível na Play Store utilizado para enviar comandos ao ESP32 via Bluetooth.
6. **Chassi do Carrinho**: Estrutura física que contém os motores e componentes eletrônicos.
7. **Rodas**: Conectadas aos motores para garantir o movimento do carrinho.

#### Funcionamento do Projeto:
O carrinho é controlado através de um aplicativo Android que envia comandos via Bluetooth para o ESP32. Cada comando corresponde a uma letra específica ('a', 'b', 'c', 'd', etc.), que controla a direção e movimento do carrinho. O ESP32 recebe esses comandos, interpreta-os e ativa os motores de acordo com a direção desejada, seja para frente, para trás, virando à direita, à esquerda ou girando em torno de seu próprio eixo.

#### Movimentos Controlados:
- **Para Frente**: O comando 'a' ativa o movimento para frente, configurando os motores para girar em sincronia no sentido de avançar.
- **Para Trás**: O comando 'c' ativa o movimento para trás, configurando os motores para girar no sentido oposto.
- **Virar à Direita**: O comando 'e' faz o carrinho virar à direita, reduzindo a velocidade de um dos motores para realizar a curva.
- **Virar à Esquerda**: O comando 'g' faz o carrinho virar à esquerda, da mesma forma, reduzindo a velocidade de um motor para realizar a curva.
- **Girar no Próprio Eixo (Direita e Esquerda)**: Com os comandos 'e' e 'g', o carrinho pode girar no próprio eixo, acionando os motores em direções opostas.
- **Parar**: Os comandos 'b', 'd', 'f', e 'h' interrompem os movimentos, fazendo o carrinho parar completamente.

#### Estrutura do Código:
1. **Bibliotecas**: A biblioteca **BluetoothSerial** é usada para habilitar a comunicação Bluetooth entre o ESP32 e o aplicativo Android.
2. **Configurações de Hardware**: Os pinos conectados aos motores são configurados para usar PWM (Modulação por Largura de Pulso), o que permite o controle da velocidade e direção dos motores.
3. **Loop Principal**: No loop principal, o ESP32 verifica constantemente se há novos comandos Bluetooth recebidos. Quando recebe um comando, ele processa as informações e ajusta os motores de acordo com a direção solicitada.
4. **Controle dos Motores**: Utilizando a ponte H, o código define os valores de PWM para os motores, controlando tanto a velocidade quanto a direção.

#### Objetivos:
- **Integração Hardware-Software**: Demonstrar o uso de microcontroladores para controlar dispositivos físicos, como motores DC.
- **Controle Remoto**: Implementar um sistema de controle remoto sem fio utilizando Bluetooth, proporcionando interação em tempo real com o carrinho.
- **Exploração de Padrões de Movimento**: Permitir o controle do carrinho em múltiplas direções, incluindo movimentos combinados como giro em torno do próprio eixo e curvas suaves.
  
#### Aplicações Futuras:
Este projeto pode ser expandido para incluir sensores de distância para evitar obstáculos, câmeras para controle remoto visual ou até mesmo integração com inteligência artificial para controle autônomo do carrinho.

#### Conclusão:
O carrinho de controle remoto via Bluetooth é uma excelente introdução ao mundo da eletrônica e programação. Ele oferece a oportunidade de aprender sobre controle de motores, comunicação sem fio e a aplicação prática de conceitos de controle de sistemas. Além disso, o uso do ESP32 torna o projeto mais versátil, possibilitando expansões futuras como controle via Wi-Fi, integração com sensores ou outros dispositivos IoT.
