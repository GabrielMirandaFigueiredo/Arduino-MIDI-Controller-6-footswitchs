#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MIDI.h>

// Configurações do display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do LCD pode variar (0x27 é comum, pode ser 0x3F)

// Pinos dos botões
const int buttonPins[6] = {5, 6, 7, 2, 3, 4};

// CC numbers para cada botão
const int ccNumbers[6] = {69, 69, 69, 52, 53, 16};  // Alteramos os primeiros três para 69

// Valores para os três primeiros botões
const int ccValues[3] = {0, 1, 2};  // Valores específicos para os três primeiros botões

// Estado anterior dos botões (para detecção de mudança)
bool lastButtonState[6] = {LOW, LOW, LOW, LOW, LOW, LOW};

// Estado de toggle dos botões 4, 5 e 6
bool toggleState[3] = {LOW, LOW, LOW};

// Posições dos textos no LCD
const int lcdPositions[6][2] = {
  {0, 0},  // Botão 1 - Canto superior esquerdo
  {6, 0},  // Botão 2 - Centro na linha de cima
  {12, 0}, // Botão 3 - Canto superior direito
  {0, 1},  // Botão 4 - Canto inferior esquerdo
  {6, 1},  // Botão 5 - Centro na linha de baixo
  {12, 1}  // Botão 6 - Canto inferior direito
};

// Cria a instância MIDI
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Inicializa o MIDI
  MIDI.begin();

  // Inicializa o LCD I2C
  lcd.init();
  lcd.backlight();

  // Configura os pinos dos botões como entrada
  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Exibe as informações iniciais no LCD
  displayInitialInfo();
}

void loop() {
  // Verifica o estado de cada botão
  for (int i = 0; i < 3; i++) {
    bool currentState = digitalRead(buttonPins[i]) == LOW; // Botão pressionado

    // Envia mensagem MIDI se o estado mudou para pressionado
    if (currentState && !lastButtonState[i]) {
      // Alterna o estado dos botões 1, 2 e 3 para os valores ccValues correspondentes
      MIDI.sendControlChange(ccNumbers[i], ccValues[i], 1); // Envia o valor MIDI
      
    }

    // Atualiza o estado anterior
    lastButtonState[i] = currentState;
  }

  // Verifica o estado de toggle dos botões 4, 5 e 6
  for (int i = 3; i < 6; i++) {
    bool currentState = digitalRead(buttonPins[i]) == LOW; // Botão pressionado

    // Envia mensagem MIDI se o estado mudou para pressionado
    if (currentState && !lastButtonState[i]) {
      toggleState[i - 3] = !toggleState[i - 3]; // Alterna o estado de toggle
      int value = toggleState[i - 3] ? 127 : 0; // Define o valor MIDI baseado no estado de toggle
      MIDI.sendControlChange(ccNumbers[i], value, 1); // Envia o valor MIDI // Atualiza o LCD para refletir o estado de toggle
    }

    // Atualiza o estado anterior
    lastButtonState[i] = currentState;
  }

  delay(5); // Pequeno delay para debouncing
}

void displayInitialInfo() {
  lcd.clear();
    lcd.setCursor(lcdPositions[0][0], lcdPositions[0][1]);
    lcd.print("SNP1");
    lcd.setCursor(6,0);
    lcd.print("SNP2");
    lcd.setCursor(12,0);
    lcd.print("SNP3");
    lcd.setCursor(0,1);
    lcd.print("FS4");
    lcd.setCursor(6,1);
    lcd.print("FS5");
    lcd.setCursor(12,1);
    lcd.print("CRG");
}