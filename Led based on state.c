const int ledr_1 = 0;
const int ledy_1 = 1;
const int ledg_1 = 2;

char* state = "r ";

void setup(){
  pinMode(ledr_1, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
}

void loop(){

  if(state[0] == 'r'){
    digitalWrite(ledr_1, HIGH);
    delay(1000);
    digitalWrite(ledr_1, LOW);
    state[0] = 'y';
  }
  
  else if(state[0] == 'y'){
    digitalWrite(ledy_1, HIGH);
    delay(1000);
    digitalWrite(ledy_1, LOW);
    state[0] = 'g';

  }
  else if(state[0] == 'g'){
    digitalWrite(ledg_1, HIGH);
    delay(1000);
    digitalWrite(ledg_1, LOW);
    state[0] = 'r';
  }
  delay(1000);
}