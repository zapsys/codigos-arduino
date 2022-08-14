// Atividade SA2
// Link para ver simulação: https://wokwi.com/projects/340010388371276370

void setup()
{
  Serial.begin(9600);	    // Inicialização da conexão serial
  pinMode(8, OUTPUT);       // Porta digital 8 (buzina) como saída
  pinMode(7, OUTPUT);	    // Porta digital 7 (led verde) como saída
  pinMode(4, OUTPUT);       // Porta digital 4 (led vermelho) como saída
  pinMode(2, INPUT);        // Porta digital 2 (sensor presença) como entrada
  digitalWrite(4, HIGH);    // Inicia com led vermelho aceso
}

void loop() {

  
  if (digitalRead(2) == HIGH) { // Checa se o estado do sensor é alto
  	digitalWrite(7, HIGH);  // Acende LED verde
    digitalWrite(4, LOW);   // Apaga LED vermelho
    tone(8,1000);		    // Buzzer acionado (frequência 1000 Hz)
    
    Serial.println("Objeto identificado!"); // Escreve mensagem no monitor serial
  }
  else {
    digitalWrite(8, LOW);   // Envia sinal para desligar o buzzer
    noTone(8);		        // Buzzer desligado
    digitalWrite(7, LOW);   // Apaga LED verde
    digitalWrite(4, HIGH);  // Acende LED vermelho
    Serial.println("Nenhum objeto sendo identificado!"); // Escreve mensagem no monitor serial
  }
  delay(10); 
}
