#include <IRremote.h>
// Map the IR code to the corresponding remote button.
// The buttons are in this order on the remote:
//    0   1   2
//    4   5   6
//    8   9  10
//   12  13  14
//   16  17  18
//   20  21  22
//   24  25  26
//
// Return -1, if supplied code does not map to a key.
int mapCodeToButton(unsigned long code) {
  // For the remote used in the Tinkercad simulator,
  // the buttons are encoded such that the hex code
  // received is of the format: 0xiivvBF00
  // Where the vv is the button value, and ii is
  // the bit-inverse of vv.
  // For example, the power button is 0xFF00BF000

  // Check for codes from this specific remote
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    // No longer need the lower 16 bits. Shift the code by 16
    // to make the rest easier.
    code >>= 16;
    // Check that the value and inverse bytes are complementary.
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  // Check if we've received a new code
  if (IrReceiver.decode()) {
    // Get the infrared code
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    // Map it to a specific button on the remote
    result = mapCodeToButton(code);
    // Enable receiving of the next value
    IrReceiver.resume();
  }
  return result;
}

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
    //int signal = pulseIn(pin, HIGH);
    int signal = 0;
    // int reading = 0, cm = 0;
    // reading = pulseIn(echo_1, HIGH);
    // cm = 0.017 * reading;
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
  IrReceiver.begin(ir_1);
  pinMode(ledr_1, OUTPUT);
  pinMode(ledy_1, OUTPUT);
  pinMode(ledg_1, OUTPUT);
  pinMode(trig_1, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(button_1, INPUT);
}

void loop(){

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

  if(seconds_1 < 0){
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