//----------------------------------------------BIBLIOTECAS--------------------------------------------
#include "BluetoothSerial.h" //esse comando inclui as instruções nescessárias para trabalhar com o Bluetooth em formato serial no Esp32

//----------------------------------------PARAMETROS DE CONFIGURAÇÃO------------------------------------
#define pinA1 25                //pino conectado a In1 da ponte H
#define pinA2 26                //pino conectado a In2 da ponte H
#define pinB1 27                //pino conectado a In3 da ponte H
#define pinB2 13                //pino conectado a In4 da ponte H
#define PWM_Freq 500            //Frequencia do PSM sendo 500 Hz a frequencia padrão do arduino, nao altere esse valor caso nao faça os calculos corretamente.
#define PWM_Res 8               //Resolução do PWM define em quantas partes será dividido do pulso, no caso o numero 8 significa que estamos dividindo ele 256 vezes, ou seja o PWM vai de 0 a 255.
BluetoothSerial SerialBT;       //Configuro o comando BluetoothSerial como SerialBT para facilitar na implementação do bluetooth no algoritmo

//------------------------------------VARIAVEIS PARA REGISTRAR DADOS DO CONTROLE---------------------------------
bool ControllerUp = 0;          //Cria variavel para memorizar quando o botao para cima é pressionado
bool ControllerDown = 0;        //Cria variavel para memorizar quando o botao para baixo é pressionado
bool ControllerRight = 0;       //Cria variavel para memorizar quando o botao para direita é pressionado
bool ControllerLeft = 0;        //Cria variavel para memorizar quando o botao para esquerda é pressionado

void setup() 
{
  //----------------------------------------CONFIGURAÇÃO BLUETOOTH------------------------------------
  Serial.begin(115200);         //Configura a comunicação serial do ESP32
  SerialBT.begin("NomeDoRobo"); //Coloque Aqui o nome do robô
  Serial.println("The device started, now you can pair it with bluetooth!"); //Envia uma mensagem para o terminal do PC dizendo que o ESP32 está ok

  //----------------------------------------CONFIGURAÇÃO DOS PINOS-----------------------------------
  ledcAttach(pinA1,PWM_Freq,PWM_Res); //Configuração do pino 1 do ESP32
  ledcAttach(pinA2,PWM_Freq,PWM_Res); //Configuração do pino 2 do ESP32
  ledcAttach(pinB1,PWM_Freq,PWM_Res); //Configuração do pino 3 do ESP32
  ledcAttach(pinB2,PWM_Freq,PWM_Res); //Configuração do pino 4 do ESP32
}

void loop() 
{
  //----------------------------------------VERIFICAÇÃO DE ENTRADAS------------------------------------
  //Verifica se o bluetooth recebeu uma mensagem
  if (SerialBT.available()) 
  {                             
    int cmd = SerialBT.read();  //Faz a leitura de qual foi a letra enviada pelo bluetooth
    switch (cmd)
    {
      case 'a':
        ControllerUp = 1;       //escreve na variavel ControllerUp quando rece 'a' do bluetooth
        break;
      case 'b':
        ControllerUp = 0;         //coloca 0 na variavel ControllerUp quando rece 'b' do bluetooth
        break;
      case 'c':
        ControllerDown = 1;      //escreve na variavel ControllerDown quando rece 'c' do bluetooth
        break;
      case 'd':
        ControllerDown = 0;      //coloca 0 na variavel ControllerDown quando rece 'd' do bluetooth
        break;
      case 'e':
        ControllerRight = 1;      //escreve na variavel ControllerRight quando rece 'e' do bluetooth
        break;
      case 'f':
        ControllerRight = 0;      //coloca 0 na variavel ControllerRight quando rece 'f' do bluetooth
        break;
      case 'g':
        ControllerLeft = 1;      //escreve na variavel ControllerLeft quando rece 'g' do bluetooth
        break;
      case 'h':
        ControllerLeft = 0;      //coloca 0 na variavel ControllerLeft quando rece 'h' do bluetooth
        break;
      default:                    //Sai do ciclo quando a letra enviada nao corresponde as letras programadas
        break;
    }
  }
  int motorPwmA1 = 0;
  int motorPwmA2 = 0;
  int motorPwmB1 = 0;
  int motorPwmB2 = 0;
  
  //----------------------------------LÓGICA DE FUNCIONAMENTO DO CARRINHO---------------------------------
  if(ControllerUp)  //Se apertar o botao pra cima ele vai escrever 1 em controller Up e vai habilitar as 4 instruções abaixo
  {
    motorPwmA1 = 100;
    motorPwmA2 = 0;
    motorPwmB1 = 100;
    motorPwmB2 = 0;
  }
  else if(ControllerDown) //Se apertar o botao pra baixo ele vai escrever 1 em ControllerDown e vai habilitar as 4 instruções abaixo
  {
    motorPwmA1 = 0;
    motorPwmA2 = 100;
    motorPwmB1 = 0;
    motorPwmB2 = 100;
  }
  else if(ControllerRight) //Se apertar o botao pra direita ele vai escrever 1 em ControllerRight e vai habilitar as 4 instruções abaixo
  {
    motorPwmA1 = 100;
    motorPwmA2 = 0;
    motorPwmB1 = 0;
    motorPwmB2 = 100;
  }
  else if(ControllerLeft) //Se apertar o botao pra esquerda ele vai escrever 1 em ControllerLeft e vai habilitar as 4 instruções abaixo
  {
    motorPwmA1 = 0;
    motorPwmA2 = 100;
    motorPwmB1 = 100;
    motorPwmB2 = 0;
  }
  else  //Se nenhum botao estiver apertado ele tira todos os valores de velocidade para o robo parar
  {
    motorPwmA1 = 0;
    motorPwmA2 = 0;
    motorPwmB1 = 0;
    motorPwmB2 = 0;
  }

  //------------------------------------ACIONAMENTO DAS SAIDAS-----------------------------------
  //envia os valores de controle para o motor
    ledcWrite(pinA2, motorPwmA2);
  ledcWrite(pinB1, motorPwmB1);
  ledcWrite(pinB2, motorPwmB2);

  delay(20);
}