#include <IRremote.h>
#include <LiquidCrystal.h>

const int rs_1 = 8, en_1 = 7, d4_1 = 12, d5_1 = 11, d6_1 = 10, d7_1 = 9;
LiquidCrystal lcd_1(rs_1, en_1, d4_1, d5_1, d6_1, d7_1);

const int ledr_1 = 0;
const int ledy_1 = 1;
const int ledg_1 = 2;

const int trig_1 = 4;
const int echo_1 = 3;
bool ultra_sonic_1 = true;

const int button_1 = 5;
bool button_pressed_1 = true;

int seconds_1 = 10; // base number
int seconds_2 = 20;
int seconds_3 = 30;

char state_1 = 'r';
const int ir_1 = 6;

int mapCodeToButton(unsigned long code) {
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    code >>= 16;
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    result = mapCodeToButton(code);
    IrReceiver.resume();
  }
  return result;
}

char get_state(char c){
  if(c == 'r'){
    c = 'y';
  }
  else if(c == 'y'){
    c = 'g';
  }
  else if(c == 'g'){
    c = 'r';
  }
  return c;
}

void light(int low1, int low2, int high){
    digitalWrite(low1, LOW);
    digitalWrite(low2, LOW);
    digitalWrite(high, HIGH);
}

int isVechileDetected(int pin){
    int signal = 0;
    //int signal = pulseIn(pin, HIGH);
    if(signal){
        return 1;
    }
    return 0;
}

int isButtonPressed(int pin){
  int signal = digitalRead(pin);
  if(signal){
      return 1;
  }
  return 0;
}

void setup()
{
  lcd_1.begin(16, 2);
  IrReceiver.begin(ir_1);
  pinMode(ledr_1, OUTPUT);
  pinMode(ledy_1, OUTPUT);
  pinMode(ledg_1, OUTPUT);
  pinMode(trig_1, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(button_1, INPUT);
}

void loop(){ 
  lcd_1.clear();
  lcd_1.setCursor(0, 1);
  lcd_1.print(seconds_1);
  
  // int reading = 0, cm = 0;
  // reading = pulseIn(echo_1, HIGH);
  // cm = 0.017 * reading;

  if(state_1 == 'r' && ultra_sonic_1 == true){
      if(isVechileDetected(echo_1) > 0){
          seconds_1 = seconds_1 - 5; // (seconds - base number / n )and (is a integer)
          // seconds_2 = seconds_2 - 5; Same base number subtracts all
          // seconds_3 = seconds_3 - 5;
          ultra_sonic_1 = false;
      }
  }

  if(state_1 == 'g' && button_pressed_1 == true){
    if(isButtonPressed(button_1) > 0){
      seconds_1 = seconds_1 - 5; // (seconds - base number / n )and (is a integer)
    // seconds_2 = seconds_2 - 5; Same base number subtracts all
    // seconds_3 = seconds_3 - 5;
    button_pressed_1 = false;
    }
  }
  
  if(state_1 == 'r'){
    light(ledg_1, ledy_1, ledr_1);
    if (readInfrared() != -1) {
      seconds_1 = 0;
      seconds_2 = 20;
      seconds_3 = 30;
    }
  }

  if(state_1 == 'y'){
    light(ledg_1, ledr_1, ledy_1);
  }
  
  if(state_1 == 'g'){
    light(ledr_1, ledy_1, ledg_1);
  }

  if(seconds_1 <= 0){
    state_1 = get_state(state_1);
    seconds_1 = 10; // (no of lanes - 1) * base number
    button_pressed_1 = true;
    ultra_sonic_1 = true;
  }

  seconds_1--;
//   seconds_2--;
//   seconds_3--;
  delay(900);

}


  