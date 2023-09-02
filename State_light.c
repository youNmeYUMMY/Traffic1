const int ledr_1 = 0;
const int ledy_1 = 1;
const int ledg_1 = 2;

char state = 'r';

void light(int low1, int low2, int high){
    digitalWrite(low1, LOW);
    digitalWrite(low2, LOW);
    digitalWrite(high, HIGH);
}

char get_state(char c){
  if(c == 'r'){
    c = 'y';
  }
  else if(state == 'y'){
    c = 'g';
  }
  else if(state == 'g'){
    c = 'r';
  }
  return c;
}

void setup(){
  pinMode(ledr_1, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
}


void loop(){
  
  if(state == 'r'){
    light(ledg_1, ledy_1, ledr_1);
    delay(1000);
    state = get_state(state);
  }
  
  else if(state == 'y'){
    light(ledg_1, ledr_1, ledy_1);
    delay(1000);
    state = get_state(state);

  }
  else if(state == 'g'){
    light(ledr_1, ledy_1, ledg_1);
    delay(1000);
    state = get_state(state);
  }

  delay(1000);
}

