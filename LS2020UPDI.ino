// Charlieplexing on an Attiny 85
// Code for making a Larson scanner
// Code by Luc Volders 2016

uint8_t pins[] = {0,1,2,3,4};
uint8_t i;

//int delay1 = 30;
//int delay2 = 10;
//long int start=0;
//long int ending=0;

const uint8_t ledpins[20][2] ={
  // this array contains all connections
  // edit the values for your won wiring
  {0,1} // L1
  ,
  {1,0} // L2
  ,
  {0,2} // L3
  ,
  {2,0} // L4
  ,
  {0,3} // L5
  ,
  {3,0} // L6
  ,
  {0,4} // L7
  ,
  {4,0} // L8
  ,
  {1,2} // L9
  ,
  {2,1} // L10
  ,
  {1,3} // L11
  , 
  {3,1} // L12
  ,
  {1,4} // L13
  ,
  {4,1} // L14
  ,  
  {2,3} // L15
  ,
  {3,2} // L16
  ,
  {2,4} // L17
  , 
  {4,2} // L18
  ,
  {3,4} // L19
  ,
  {4,3} // L20
};

void setup()
{
//  // First we put all leds off
//  alloff();
//  delay(1);
}

void loop()
{
  // Larson forward
  for(i = 0; i < 19; i++)
  {
    ledon(i);
    delay(40);
    alloff();
  } 
  // larson backwards
  for(i = 19; i >0 ; i--)
  {
    ledon(i);
    delay(40);
    alloff();
  }
  alloff();  
}

void alloff() 
// This routines puts all leds off
{
  for(uint8_t i = 0; i < 5; i++)
  {
    pinMode (pins[i], INPUT);
    digitalWrite (pins[i], LOW);
  }
}

void ledon(uint8_t lednr) 
// This routine puts a led on 
{
  uint8_t pluspin = ledpins[lednr][0];
  uint8_t negpin = ledpins[lednr][1];
  pinMode (pluspin, OUTPUT);
  digitalWrite (pluspin, HIGH);
  pinMode (negpin, OUTPUT);
  digitalWrite (negpin, LOW);
  delay(1);
}
