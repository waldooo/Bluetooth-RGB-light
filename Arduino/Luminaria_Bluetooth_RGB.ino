/*
  Sketch arduino por Waldo Costa
  http://www.waldocosta.com.br
  atualizado em: 2017 nov 18

  Baseado parcialmente no sketch de Tom Igoe disponível em:
  http://www.arduino.cc/en/Tutorial/SerialEvent
*/

#include <Adafruit_NeoPixel.h>

#define BRILHO    255 // valor de 0 a 255
#define PIXEL_COUNT 5 //número de pixels em cada fita de led

// utilizado para debug:
int delayval = 10; // valor de delay entre a atualização de cada pixel

// valores iniciais para vermelho, verde e azul
int vermelho_int = 0;

int verde_int = 0;

int azul_int = 0;


// foram utilizadas 4 fitas de leds: strip1 a 4, nos pinos 5, 6, 9 e 10.
// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(PIXEL_COUNT, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIXEL_COUNT, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(PIXEL_COUNT, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(PIXEL_COUNT, 10, NEO_GRB + NEO_KHZ800);



// função utilizada para preencher todos os
// leds com uma única cor
void colorWipe(uint32_t c) {
  for (uint16_t i = 0; i < PIXEL_COUNT; i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    strip2.setPixelColor(i, c);
    strip2.show();
    strip3.setPixelColor(i, c);
    strip3.show();
    strip4.setPixelColor(i, c);
    strip4.show();
  }
}

// desliga todos os leds ao iniciar
void desliga_todos() {
  colorWipe(strip1.Color(0, 0, 0));
}


void setup() {

  // initialize serial:
  Serial.begin(9600);

  strip1.setBrightness(BRILHO);
  strip1.begin();
  strip1.show();
  strip2.setBrightness(BRILHO);
  strip2.begin();
  strip2.show();
  strip3.setBrightness(BRILHO);
  strip3.begin();
  strip3.show();
  strip4.setBrightness(BRILHO);
  strip4.begin();
  strip4.show();

  // envia o valor RGB (0,0,0) para todos pixels
  desliga_todos();
}

void loop() {


  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:
    int green = Serial.parseInt();
    // do it again:
    int blue = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {

      vermelho_int = red;
      verde_int    = green;
      azul_int     = blue;

    }
  }

  //insere a cor nos pixels
  for (int k = 0; k < PIXEL_COUNT; k++) {

    // envia o valor de vermelho, verde e azul para o pixel de número k da fita 1
    strip1.setPixelColor(k, strip1.Color(vermelho_int, verde_int, azul_int)); //
    strip1.show();
    // o delay pode ser ativado para observar a ordem em que as cores são atualizadas
    delay(delayval);

    // envia o valor de vermelho, verde e azul para o pixel de número k da fita 2
    strip2.setPixelColor(k, strip2.Color(vermelho_int, verde_int, azul_int)); //
    strip2.show();
    delay(delayval);

    // envia o valor de vermelho, verde e azul para o pixel de número k da fita 31
    strip3.setPixelColor(k, strip3.Color(vermelho_int, verde_int, azul_int)); //
    strip3.show();
    delay(delayval);

    // envia o valor de vermelho, verde e azul para o pixel de número k da fita 4
    strip4.setPixelColor(k, strip4.Color(vermelho_int, verde_int, azul_int)); //
    strip4.show();
    delay(delayval);
  }


}//fim do loop



