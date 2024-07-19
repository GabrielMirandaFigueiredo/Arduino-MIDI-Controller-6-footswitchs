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

// String de teste para verificação do LCD
const char testString[] = "versao 2.1";

// Texto para os botões
const char snp1[] = "SNP1";
const char snp2[] = "SNP2";
const char snp3[] = "SNP3";
const char fs4[] = "FS4";
const char fs5[] = "FS5";
const char pag2[] = "PAG2";
const char fx1[] = "FX1";
const char fx2[] = "FX2";
const char mod[] = "MOD";
const char dly[] = "DLY";
const char rev[] = "REV";
const char pag1[] = "PAG1";

// Cria a instância MIDI
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Inicializa o MIDI
  MIDI.begin();

  // Pequeno atraso antes de inicializar o LCD I2C
  delay(1000);  // Adiciona um atraso de 1000ms

  // Inicializa o LCD I2C
  lcd.init();
  lcd.backlight();

  // Mostra a string de teste por 1 segundo
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(testString);
  delay(3000);

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

  delay(50); // Pequeno delay para debouncing
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
      int value = toggleStatePage2[i] ? 0 : 127; // Define o valor MIDI baseado no estado de toggle
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
    lcd.print(snp1);
    lcd.setCursor(lcdPositions[1][0], lcdPositions[1][1]);
    lcd.print(snp2);
    lcd.setCursor(lcdPositions[2][0], lcdPositions[2][1]);
    lcd.print(snp3);
    lcd.setCursor(lcdPositions[3][0], lcdPositions[3][1]);
    lcd.print(fs4);
    lcd.setCursor(lcdPositions[4][0], lcdPositions[4][1]);
    lcd.print(fs5);
    lcd.setCursor(lcdPositions[5][0], lcdPositions[5][1]);
    lcd.print(pag2);
  } else if (currentPage == 2) {
    // Página 2 - exibe as informações MIDI CC
    lcd.setCursor(lcdPositions[0][0], lcdPositions[0][1]);
    lcd.print(fx1);
    lcd.setCursor(lcdPositions[1][0], lcdPositions[1][1]);
    lcd.print(fx2);
    lcd.setCursor(lcdPositions[2][0], lcdPositions[2][1]);
    lcd.print(mod);
    lcd.setCursor(lcdPositions[3][0], lcdPositions[3][1]);
    lcd.print(dly);
    lcd.setCursor(lcdPositions[4][0], lcdPositions[4][1]);
    lcd.print(rev);
    lcd.setCursor(lcdPositions[5][0], lcdPositions[5][1]);
    lcd.print(pag1);
  }
}
