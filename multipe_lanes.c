#include <LiquidCrystal.h>

int seconds_1 = 10; // base number is supposed to be this but currently it is used as 5 in rest of programme
int seconds_2 = seconds_1 + 10;
int seconds_3 = seconds_2 + 10;

// lane 1 ----------------------------

const int rs_1 = 1, en_1 = 2, d4_1 = 4, d5_1 = 5, d6_1 = 6, d7_1 = 7;
LiquidCrystal lcd_1(rs_1, en_1, d4_1, d5_1, d6_1, d7_1);

// const int ledr_1 = 0;
// const int ledy_1 = 1;
// const int ledg_1 = 2;

const int trig_1 = 10;
const int echo_1 = 11;
bool ultra_sonic_1 = true;

// const int button_1 = 5;
// bool button_pressed_1 = true;

char state_1 = 'r';
// const int ir_1 = 6;

// lane 2 ------------------------------

const int rs_2 = 14, en_2 = 30, d4_2 = 22, d5_2 = 24, d6_2 = 26, d7_2 = 28;
LiquidCrystal lcd_2(rs_2, en_2, d4_2, d5_2, d6_2, d7_2);

// const int ledr_2 = 0;
// const int ledy_2 = 1;
// const int ledg_2 = 2;

const int trig_2 = 12;
const int echo_2 = 13;
bool ultra_sonic_2 = true;

// const int button_2 = 5;
// bool button_pressed_2 = true;

char state_2 = 'r';
// const int ir_2 = 6;

// lane 3 --------------------------------

const int rs_3 = 16, en_3 = 40, d4_3 = 32, d5_3 = 34, d6_3 = 36, d7_3 = 38;
LiquidCrystal lcd_3(rs_3, en_3, d4_3, d5_3, d6_3, d7_3);

// const int ledr_3 = 0;
// const int ledy_3 = 1;
// const int ledg_3 = 2;

const int trig_3 = 8;
const int echo_3 = 9;
bool ultra_sonic_3 = true;

// const int button_3 = 5;
// bool button_pressed_3 = true;

char state_3 = 'r';
// const int ir_3 = 6;

// int mapCodeToButton(unsigned long code) {
//   if ((code & 0x0000FFFF) == 0x0000BF00) {
//     code >>= 16;
//     if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
//       return code & 0xFF;
//     }
//   }
//   return -1;
// }

// int readInfrared(){
//   int result = -1;
//   if (IrReceiver_1.decode()) {
//     unsigned long code = IrReceiver.decodedIRData.decodedRawData;
//     result = mapCodeToButton(code);
//     IrReceiver.resume();
//   }else if (IrReceiver_2.decode()) {
//     unsigned long code = IrReceiver.decodedIRData.decodedRawData;
//     result = mapCodeToButton(code);
//     IrReceiver.resume();
//   }else if (IrReceiver_3.decode()){
//     unsigned long code = IrReceiver.decodedIRData.decodedRawData;
//     result = mapCodeToButton(code);
//     IrReceiver.resume();
//   }
//   return result;
// }


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

// void light(int low1, int low2, int high){
//     digitalWrite(low1, LOW);
//     digitalWrite(low2, LOW);
//     digitalWrite(high, HIGH);
// }

int isVechileDetected(int pin){
    // int signal = 0;
    int signal = pulseIn(pin, HIGH);
    if(signal){
        return 1;
    }
    return 0;
}

// int isButtonPressed(int pin){
//   int signal = digitalRead(pin);
//   if(signal){
//       return 1;
//   }
//   return 0;
// }

void setup()
{
    lcd_1.begin(16, 2);
    // IrReceiver_1.begin(ir_1);
    // pinMode(ledr_1, OUTPUT);
    // pinMode(ledy_1, OUTPUT);
    // pinMode(ledg_1, OUTPUT);
    pinMode(trig_1, OUTPUT);
    pinMode(echo_1, INPUT);
    // pinMode(button_1, INPUT);

    lcd_2.begin(16, 2);
    // IrReceiver_2.begin(ir_2);
    // pinMode(ledr_2, OUTPUT);
    // pinMode(ledy_2, OUTPUT);
    // pinMode(ledg_2, OUTPUT);
    pinMode(trig_2, OUTPUT);
    pinMode(echo_2, INPUT);
    // pinMode(button_2, INPUT);

    lcd_3.begin(16, 2);
    // IrReceiver_3.begin(ir_3);
    // pinMode(ledr_3, OUTPUT);
    // pinMode(ledy_3, OUTPUT);
    // pinMode(ledg_3, OUTPUT);
    pinMode(trig_3, OUTPUT);
    pinMode(echo_3, INPUT);
    // pinMode(button_3, INPUT);
}

void loop(){

    // Lane 1 ----------------------------------------------------------------------------
    lcd_1.clear();
    lcd_1.setCursor(0, 1);
    lcd_1.print(seconds_1);

    if(state_1 == 'r' && ultra_sonic_1 == true){
        if(isVechileDetected(echo_1) > 100){
            seconds_1 = seconds_1 - 5;
            seconds_2 = seconds_2 - 5;
            seconds_3 = seconds_3 - 5;
            ultra_sonic_1 = false;
        }
    }

    // if(state_1 == 'g' && button_pressed_1 == true){
    //     if(isButtonPressed(button_1) > 0){
    //         seconds_1 = seconds_1 - 5;
    //         seconds_2 = seconds_2 - 5;
    //         seconds_3 = seconds_3 - 5;
    //         button_pressed_1 = false;
    //     }
    // }

    // if (state_1 == 'r' && readInfrared() != -1) {
    //     seconds_1 = 0;
    //     seconds_2 = 20;
    //     seconds_3 = 30;
    // }
    
    if(state_1 == 'r'){
        // light(ledg_1, ledy_1, ledr_1);
        lcd_1.setCursor(1, 0);
        lcd_1.print("RED");    
    }else if(state_1 == 'y'){
        // light(ledg_1, ledr_1, ledy_1);
        lcd_1.setCursor(1, 0);
        lcd_1.print("Yellow");
    }else if(state_1 == 'g'){
        // light(ledr_1, ledy_1, ledg_1);
        lcd_1.setCursor(1, 0);
        lcd_1.print("Green");
    }

    if(seconds_1 <= 0){
        state_1 = get_state(state_1);
        seconds_1 = 30; // (no of lanes) * base number
        // button_pressed_1 = true;
        ultra_sonic_1 = true;
    }

    // Lane 2 ----------------------------------------------------------------------------
    lcd_2.clear();
    lcd_2.setCursor(0, 1);
    lcd_2.print(seconds_2);

    if(state_2 == 'r' && ultra_sonic_2 == true){
        if(isVechileDetected(echo_2) > 100){
            seconds_1 = seconds_1 - 5;
            seconds_2 = seconds_2 - 5;
            seconds_3 = seconds_3 - 5;
            ultra_sonic_2 = false;
        }
    }

    // if(state_2 == 'g' && button_pressed_2 == true){
    //     if(isButtonPressed(button_1) > 0){
    //         seconds_1 = seconds_1 - 5;
    //         seconds_2 = seconds_2 - 5;
    //         seconds_3 = seconds_3 - 5;
    //         button_pressed_2 = false;
    //     }
    // }

    // if (state_2 == 'r' && readInfrared() != -1) {
    //     seconds_2 = 0;
    //     seconds_3 = 20;
    //     seconds_1 = 30;
    // }
    
    if(state_2 == 'r'){
        // light(ledg_2, ledy_2, ledr_2);
        lcd_2.setCursor(1, 0);
        lcd_2.print("RED");    
    }else if(state_2 == 'y'){
        // light(ledg_2, ledr_2, ledy_2);
        lcd_2.setCursor(1, 0);
        lcd_2.print("Yellow");
    }else if(state_2 == 'g'){
        // light(ledr_2, ledy_2, ledg_2);
        lcd_2.setCursor(1, 0);
        lcd_2.print("Green");
    }

    if(seconds_2 <= 0){
        state_2 = get_state(state_2);
        seconds_2 = 30; // (no of lanes) * base number
        // button_pressed_2 = true;
        ultra_sonic_2 = true;
    }

    // Lane 3 ----------------------------------------------------------------------------
    lcd_3.clear();
    lcd_3.setCursor(0, 1);
    lcd_3.print(seconds_3);

    if(state_3 == 'r' && ultra_sonic_3 == true){
        if(isVechileDetected(echo_1) > 100){
            seconds_1 = seconds_1 - 5;
            seconds_2 = seconds_2 - 5;
            seconds_3 = seconds_3 - 5;
            ultra_sonic_3 = false;
        }
    }

    // if(state_3 == 'g' && button_pressed_3 == true){
    //     if(isButtonPressed(button_1) > 0){
    //         seconds_1 = seconds_1 - 5;
    //         seconds_2 = seconds_2 - 5;
    //         seconds_3 = seconds_3 - 5;
    //         button_pressed_3 = false;
    //     }
    // }

    // if (state_3 == 'r' && readInfrared() != -1) {
    //     seconds_3 = 0;
    //     seconds_1= 20;
    //     seconds_2 = 30;
    // }
    
    if(state_3 == 'r'){
        // light(ledg_3, ledy_3, ledr_3);
        lcd_3.setCursor(1, 0);
        lcd_3.print("RED");    
    }else if(state_3 == 'y'){
        // light(ledg_3, ledr_3, ledy_3);
        lcd_3.setCursor(1, 0);
        lcd_3.print("Yellow");
    }else if(state_3 == 'g'){
        // light(ledr_3, ledy_3, ledg_3);
        lcd_3.setCursor(1, 0);
        lcd_3.print("Green");
    }

    if(seconds_3 <= 0){
        state_3 = get_state(state_1);
        seconds_3 = 30; // (no of lanes) * base number
        // button_pressed_3 = true;
        ultra_sonic_3 = true;
    }

    seconds_1--;
    seconds_2--;
    seconds_3--;
    delay(900);
}


  