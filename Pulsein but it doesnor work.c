const int ledr_1 = 0;
const int ledy_1 = 1;
const int ledg_1 = 2;

const int trig_1 = 4;
const int echo_1 = 3;

char* state = "r ";

void setup(){
    Serial.begin(9600);
    pinMode(ledr_1, OUTPUT);
    pinMode(echo_1, INPUT);
}

void loop(){
    pinMode(trig_1, OUTPUT);
    int temp = pulseIn(echo_1, HIGH);
    Serial.println(temp);
    if(temp == HIGH){
        digitalWrite(ledr_1, HIGH);
    }else{
        digitalWrite(ledr_1, LOW);
    }
}