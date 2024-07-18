#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MIDI.h>

// Configurações do display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do LCD pode variar (0x27 é comum, pode ser 0x3F)

// Pinos dos botões
const int buttonPins[6] = {5, 6, 7, 2, 3, 4};

// CC numbers para cada botão na página 1
const int ccNumbersPage1[6] = {69, 69, 69, 52, 53};  // Alteramos os primeiros três para 69

// CC numbers para cada botão na página 2
const int ccNumbersPage2[6] = {82, 83, 84, 85, 86};  // Alterados conforme sua solicitação

// Valores para os três primeiros botões
const int ccValuesPage1[3] = {0, 1, 2};  // Valores específicos para os três primeiros botões

// Estado anterior dos botões (para detecção de mudança)
bool lastButtonState[6] = {LOW, LOW, LOW, LOW, LOW, LOW};

// Estado de toggle dos botões em ambas as páginas
bool toggleStatePage1[5] = {LOW, LOW, LOW, LOW, LOW};
bool toggleStatePage2[5] = {LOW, LOW, LOW, LOW, LOW};

// Posições dos textos no LCD
const int lcdPositions[6][2] = {
  {0, 0},  // Botão 1 - Canto superior esquerdo
  {6, 0},  // Botão 2 - Centro na linha de cima
  {12, 0}, // Botão 3 - Canto superior direito
  {0, 1},  // Botão 4 - Canto inferior esquerdo
  {6, 1},  // Botão 5 - Centro na linha de baixo
  {12, 1}  // Botão 6 - Canto inferior direito
};

// Estado da página atual
int currentPage = 1; // Começa na página 1

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

  // Exibe as informações iniciais no LCD de acordo com a página atual
  updatePage();
}

void loop() {
  // Verifica o estado do botão de troca de página (botão 6)
  bool pageButtonState = digitalRead(buttonPins[5]) == LOW; // Botão pressionado

  if (pageButtonState && !lastButtonState[5]) {
    currentPage = (currentPage == 1) ? 2 : 1; // Alterna entre página 1 e página 2
    updatePage(); // Atualiza o LCD e as configurações MIDI para refletir a nova página
  }
  lastButtonState[5] = pageButtonState; // Atualiza o estado anterior do botão de troca de página

  // Processa botões com base na página atual
  if (currentPage == 1) {
    // Página 1
    handlePage1Buttons();
  } else {
    // Página 2
    handlePage2Buttons();
  }

  delay(10); // Pequeno delay para debouncing
}

void handlePage1Buttons() {
  for (int i = 0; i < 5; i++) {
    bool currentState = digitalRead(buttonPins[i]) == LOW; // Botão pressionado

    if (currentState && !lastButtonState[i]) {
      int ccNumber = ccNumbersPage1[i];
      int value = (i < 3) ? ccValuesPage1[i] : (toggleStatePage1[i] ? 127 : 0); // Define o valor MIDI baseado no estado de toggle
      MIDI.sendControlChange(ccNumber, value, 1); // Envia o valor MIDI
      toggleStatePage1[i] = !toggleStatePage1[i]; // Alterna o estado de toggle
    }

    lastButtonState[i] = currentState; // Atualiza o estado anterior
  }
}

void handlePage2Buttons() {
  for (int i = 0; i < 5; i++) {
    bool currentState = digitalRead(buttonPins[i]) == LOW; // Botão pressionado

    if (currentState && !lastButtonState[i]) {
      int ccNumber = ccNumbersPage2[i];
      int value = toggleStatePage2[i] ? 127 : 0; // Define o valor MIDI baseado no estado de toggle
      MIDI.sendControlChange(ccNumber, value, 1); // Envia o valor MIDI
      toggleStatePage2[i] = !toggleStatePage2[i]; // Alterna o estado de toggle
    }

    lastButtonState[i] = currentState; // Atualiza o estado anterior
  }
}

void updatePage() {
  lcd.clear();
  if (currentPage == 1) {
    // Página 1 - exibe as informações padrão
    lcd.setCursor(lcdPositions[0][0], lcdPositions[0][1]);
    lcd.print("SNP1");
    lcd.setCursor(lcdPositions[1][0], lcdPositions[1][1]);
    lcd.print("SNP2");
    lcd.setCursor(lcdPositions[2][0], lcdPositions[2][1]);
    lcd.print("SNP3");
    lcd.setCursor(lcdPositions[3][0], lcdPositions[3][1]);
    lcd.print("FS4");
    lcd.setCursor(lcdPositions[4][0], lcdPositions[4][1]);
    lcd.print("FS5");
    lcd.setCursor(lcdPositions[5][0], lcdPositions[5][1]);
    lcd.print("PAG2");
  } else if (currentPage == 2) {
    // Página 2 - exibe as informações MIDI CC
    lcd.setCursor(lcdPositions[0][0], lcdPositions[0][1]);
    lcd.print("FX1");
    lcd.setCursor(lcdPositions[1][0], lcdPositions[1][1]);
    lcd.print("FX2");
    lcd.setCursor(lcdPositions[2][0], lcdPositions[2][1]);
    lcd.print("MOD");
    lcd.setCursor(lcdPositions[3][0], lcdPositions[3][1]);
    lcd.print("DLY");
    lcd.setCursor(lcdPositions[4][0], lcdPositions[4][1]);
    lcd.print("REV");
    lcd.setCursor(lcdPositions[5][0], lcdPositions[5][1]);
    lcd.print("PAG1");
  }
}
