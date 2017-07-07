#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>


#define NUMPIXELS 8
#define NEOPIXEL_PIN 3

// Make a NeoPixel object for the LED strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Make a LiquidCrystal object for the 16x2 LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Make a servo object
Servo servo;
int servo_position = 0;

uint8_t colors[] = {
  21, 29, 132,
  255, 113, 0,
  113, 0, 255,
  255, 0, 15,
  0, 255, 113,
  0, 15, 255,
  255, 113, 0,
  113, 0, 255,
};

bool rotate = 1;
int delay_time = 30;

void setup() {


  // setup for the LCD
  lcd.begin(16, 2);
  lcd.print("hello, world!");

  // setup for the servo motor
  servo.attach(5);

  // setup for the speaker
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);

  // setup for the LED strip
  pixels.begin();
  pixels.show();

  
  // setup for serial terminal
  Serial.begin(9600);
}

void loop() {
  // draw a pattern on the LED strip
  one_two_blink();

  // write number of seconds since startup on the LCD
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  // read from the photoresistor, make a sound on the buzzer if it is pressed
  int read_value = analogRead(0);
  int button_pressed = digitalRead(6);
  if (read_value < 200 || button_pressed) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  // print the value read from the photoresistor
  Serial.println(read_value);

  servo.write(servo_position);
  if (servo_position++ > 180) {
    servo_position = 0;
  }

}
