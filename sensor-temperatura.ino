// Função: Verificação, via acendimento de LEDs, da variação de temperatura registrado por um sensor.
// Elaborado em: 10/08/2022 


// Configuração inicial
void setup()
{
    // Pino de entrada principal (A0 analógico)
    pinMode(A0, INPUT);
    Serial.begin(9600);

    // Definição dos pinos de Saída (Pinos digitais)
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);

    // Led da placa Arduino (padrão)
    pinMode(LED_BUILTIN, OUTPUT);
}
// Início do loop para iniciar a simulação/operação
void loop()
{
    // Se o sinal de entrada está entre 20 e 100 acende o LED conectado à saída 7 (HIGH)
    if (analogRead(A0) >= 20 && analogRead(A0) <= 100)
    {
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    }
    // Senão se o sinal de entrada está entre 101 e 200 acende o LED conectado à saída 6 (HIGH)
    else if (analogRead(A0) >= 101 && analogRead(A0) <= 200)
    {
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
    }
    // Senão sobra o último caso onde o sinal de entrada é maior que 200, daí acende o LED conectado à saída 5 (HIGH)
    else
    {
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
    }
    // Coloca o estado de todos os LEDs em LOW (desligado) caso não se enquadre nas condições
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);

    // Delay um pouco para melhorar a performance da simulação
    delay(10);
}