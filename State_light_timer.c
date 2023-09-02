const int ledr_1 = 0;
const int ledy_1 = 1;
const int ledg_1 = 2;

const int trig_1 = 4;
const int echo_1 = 3;

int seconds_1 = 5; // base number
int seconds_2 = 10;
int seconds_3 = 15;

char state_1 = 'r';

void light(int low1, int low2, int high){
    digitalWrite(low1, LOW);
    digitalWrite(low2, LOW);
    digitalWrite(high, HIGH);
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

void setup(){
  pinMode(ledr_1, OUTPUT);
  pinMode(trig_1, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(ledy_1, OUTPUT);
  pinMode(ledg_1, OUTPUT);
}

void loop(){

  if(seconds_1 < 0){
      state_1 = get_state(state_1);
      seconds_1 = 5; // (no of lanes - 1) * base number
  }
  
  if(state_1 == 'r'){
    light(ledg_1, ledy_1, ledr_1);
  }

  if(state_1 == 'y'){
    light(ledg_1, ledr_1, ledy_1);
  }
  
  if(state_1 == 'g'){
    light(ledr_1, ledy_1, ledg_1);
  }

  seconds_1--;
  seconds_2--;
  seconds_3--;
  delay(900);
}

