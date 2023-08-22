// Concept code
// The lane one two and three each is supposed to have the difference of n seconds;
// If one lane timer is reduced then all other lanes timer is reduced with the same number to keep up with changing difference
// Using timer = 0 or timer < 0 we switch state and rest of program acts accourdingly to the state.
// if green ligt then state is switched and 100 seconds is set. While the other lanes will have 0 and 50 seconds remainaing in all cases if the seconds is 50.

char state1 = 'r';
char state2 = 'r';
char state3 = 'r';

const int trig1 = 3;
const int trig2 = 5;
const int trig3 = 10;

const int echo1 = 4;
const int echo2 = 6;
const int echo3 = 11;

const int button_1 = 1;
const int button_2 = 1;
const int button_3 = 1;

const int pinr_1 = 2;
const int piny_1 = 1;
const int ping_1 = 0;

const int pinr_2 = 7;
const int piny_2 = 8;
const int ping_2 = 9;

const int pinr_3 = 12;
const int piny_3 = 1;
const int ping_3 = 13;

const int button_subtract = 3;
const int distance_subtract = 5;

const int seconds = 10;

int timer1 = seconds;
int timer2 = seconds * 2;
int timer3 = seconds * 3;

int lanes = 3;

bool distance = false;
bool button = false;

int distance_reading_1 = false;
int distance_reading_2 = false;
int distance_reading_3 = false;

int button_pressed_1 = false;
int button_pressed_2 = false;
int button_pressed_3 = false;

bool reset_1 = true;
bool reset_2 = true;

void setup(){
    
}

void loop(){

    // Read from ultra sonic distance and button
    pinMode(trig1, OUTPUT); //This help clear the trig pins
    pinMode(trig2, OUTPUT);
    pinMode(trig3, OUTPUT);

    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);

    distance_reading_1 = pulseIn(echo1, HIGH);
    distance_reading_2 = pulseIn(echo2, HIGH);
    distance_reading_3 = pulseIn(echo3, HIGH);

    if (distance_reading_1 == HIGH || distance_reading_2 == HIGH || distance_reading_3 == HIGH){
        if (state1 == 'r' || state2 == 'r' || state3 == 'r'){
            distance = true;
        }
    }
    if (button_pressed_1 == HIGH || button_pressed_2 == HIGH || button_pressed_3 == HIGH){
        if (state1 == 'g' || state2 == 'g' || state3 == 'g'){
            button = true;
        }
    }
    // end

    // Reduce timer
    if (distance == true && reset_1 == true){
        reset_1 = false;
        timer1 = timer1 - distance_subtract;
        timer2 = timer2 - distance_subtract;
        timer3 = timer3 - distance_subtract;
    }
    if (button == true && reset_2 == true){
        reset_2 = false;
        timer1 = timer1 - button_subtract;
        timer2 = timer2 - button_subtract;
        timer3 = timer3 - button_subtract;
    }
    //end
    
    // This code switch state and timer ofter counter hits 0
    // start
    if (timer1 < 1){
        if (state1 = 'r'){
            timer1 = seconds;
            state1 = 'g';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true;
        }
        else if (state1 = 'g'){
            timer1 = (lanes - 1) * seconds; // Basically 100 seconds if seconds = 50 seconds; The other lanes have 0 and 50 seconds respectively
            state1 = 'r';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true; 
        }
    }else if (timer2 < 1){
        if (state2 = 'r'){
            timer2 = seconds;
            state2 = 'g';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true;    
        } 
        else if (state2 = 'g'){
            timer2 = (lanes - 1) * seconds;
            state2 = 'r';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true;
        }
    }
    else if (timer3 < 1){
        if (state3 = 'r'){
            timer3 = seconds;
            state3 = 'g';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true;
        }  
        else if (state3 = 'g'){
            timer3 = (lanes - 1) * seconds;
            state3 = 'r';
            distance = false;
            button = false; 
            reset_1 = true;
            reset_2 = true;
        } 
    }
    // end

    // Traffic 1
    if (state1 == 'r'){
        digitalWrite(pinr_1, HIGH);
        digitalWrite(piny_1, LOW);
        digitalWrite(ping_1, LOW);
    }else if (state1 == 'y'){
        digitalWrite(pinr_1, LOW);
        digitalWrite(piny_1, HIGH);
        digitalWrite(ping_1, LOW);
    }else if (state1 == 'g'){
        digitalWrite(pinr_1, LOW);
        digitalWrite(piny_1, LOW);
        digitalWrite(ping_1, HIGH);
    }
    //end

    // Traffic 2
    if (state2 = 'r'){
        digitalWrite(pinr_2, HIGH);
        digitalWrite(piny_2, LOW);
        digitalWrite(ping_2, LOW);
    }else if (state2 == 'y'){
        digitalWrite(pinr_2, LOW);
        digitalWrite(piny_2, HIGH);
        digitalWrite(ping_2, LOW);
    }else if (state2 == 'g'){
        digitalWrite(pinr_2, LOW);
        digitalWrite(piny_2, LOW);
        digitalWrite(ping_2, HIGH);
    }
    //end

    // Traffic 3
    if (state3 = 'r'){
        digitalWrite(pinr_3, HIGH);
        digitalWrite(piny_3, LOW);
        digitalWrite(ping_3, LOW);
    }else if (state3 == 'y'){
        digitalWrite(pinr_3, LOW);
        digitalWrite(piny_3, HIGH);
        digitalWrite(ping_3, LOW);
    }else if (state3 == 'g'){
        digitalWrite(pinr_3, LOW);
        digitalWrite(piny_3, LOW);
        digitalWrite(ping_3, HIGH);
    }
    //end

    // Decrease timer by one
    timer1--;
    timer2--;
    timer3--;

    // Delay the system 1 second
    delay(10);
}