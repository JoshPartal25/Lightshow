// C++ code
//
#define GREEN_PIN 12
#define YELLOW_PIN 11
#define RED_PIN 10
#define BUTTON 9

int red = 4;
int green = 3;
int blue = 2;

// INPUT: potentiometer should be connected to 5V and GND
int potPin = A0;
int potVal = 0;

// Program variables
int redVal = 0; //variables to store the values to send to the pins
int grnVal = 0;
int bluVal = 0;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT); //sets the pins as output
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);


  //Serial.setTimeout(10);
  //pinMode(GREEN_PIN, OUTPUT);
  //pinMode(YELLOW_PIN, OUTPUT);
  //pinMode(RED_PIN, OUTPUT);
  //pinMode(BUTTON, INPUT);
  //pinMode(POTENTI_PIN, INPUT);
}

void loop(){

//put your main code here, to run repeatedly:
  Serial.println(digitalRead(BUTTON));
  if(digitalRead(BUTTON) == 1){ //button in pin 1 will read 1 in synapse
    digitalWrite(RED_PIN, HIGH); //when pressing button will turn the red on
  } else {
    digitalWrite(RED_PIN, LOW); //when the button is not being pressed, red LED will not light up
  }

  digitalWrite(GREEN_PIN, HIGH); //green light turns on first
  delay(200);
  digitalWrite(YELLOW_PIN, HIGH); //yellow light turns on second
  delay(200);
  digitalWrite(RED_PIN, HIGH); //red light turns on last

  delay(1500);
  //all three lights off preparing for flashing pattern
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  
  delay(100);
  //green light flashes in pattern 4 times
  digitalWrite(GREEN_PIN, HIGH); 
  delay(50);
  digitalWrite(GREEN_PIN, LOW);
  delay(50);
  digitalWrite(GREEN_PIN, HIGH);
  delay(50);
  digitalWrite(GREEN_PIN, LOW);
  delay(50);
  digitalWrite(GREEN_PIN, HIGH);
  delay(50);
  digitalWrite(GREEN_PIN, LOW);
  delay(50);
  digitalWrite(GREEN_PIN, HIGH);
  delay(50);
  digitalWrite(GREEN_PIN, LOW);

  delay(100);
  //yellow light flashes in the same pattern as green 4 times 
  digitalWrite(YELLOW_PIN, HIGH);
  delay(50);
  digitalWrite(YELLOW_PIN, LOW);
  delay(50);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(50);
  digitalWrite(YELLOW_PIN, LOW);
  delay(50);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(50);
  digitalWrite(YELLOW_PIN, LOW);
  delay(50);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(50);
  digitalWrite(YELLOW_PIN, LOW);

  delay(100);
  //red light flashes in same pattern as green and yellow 4 times
  digitalWrite(RED_PIN, HIGH);
  delay(50);
  digitalWrite(RED_PIN, LOW);
  delay(50);
  digitalWrite(RED_PIN, HIGH);
  delay(50);
  digitalWrite(RED_PIN, LOW);
  delay(50);
  digitalWrite(RED_PIN, HIGH);
  delay(50);
  digitalWrite(RED_PIN, LOW);
  delay(50);
  digitalWrite(RED_PIN, HIGH);
  delay(50);
  digitalWrite(RED_PIN, LOW);
  

  delay(700);

  if(Serial.available() > 0){
    int flash = Serial.parseInt();
    Serial.println("flash #    :");
  }
  

  //making the LED's flash in a pattern
  for(int i = 0; i < 7; i++){
    digitalWrite(GREEN_PIN, HIGH);
    delay(200);
    digitalWrite(YELLOW_PIN, HIGH);
    delay(200);
    digitalWrite(RED_PIN, HIGH);
    delay(200);
  }


    //  Serial.println(digitalRead(BUTTON));


if(Serial.available() > 0){
  String color = "red";
  color = Serial.readString();
if(color.startsWith("yellow")){
  digitalWrite(YELLOW_PIN, HIGH);
}
else{
  Serial.println("yellow didn't work");
}

if(color.startsWith("red")){
  digitalWrite(RED_PIN, HIGH);
}
  else{
    Serial.println("red didn't work");
}

if(color.startsWith("green")){
  digitalWrite(GREEN_PIN, HIGH);
}
  else{
    Serial.println("green didn't work");
}
}

  {
    potVal = analogRead(potPin); //read the potentiometer value at the input pin
  
    if (potVal < 341) //lowest third of the ptentiometer's range(0-340)
  {
      potVal = (potVal * 3) / 4; //Normalize to 0-255
    
      redVal = 256 - potVal; //Red from full to off
      grnVal = potVal; //Green from off to full
      bluVal = 1; //Blue off
  }
  else if(potVal < 682) //Middle third of potentiometer's range (341-681)
  {
      potVal = ( (potVal - 341) * 3) / 4; //Normalize to 0-255

      redVal = 1; //Red off
      grnVal = 256 - potVal; //Green from full to off
      bluVal = potVal; //Blue from off to full
  }
  else //Upper third of potentiometer's range (682-1023)
  {
      potVal = ( (potVal - 683) * 3) / 4; //Normalize to 0-255

      redVal = potVal; //Red from off to full
      grnVal = 1; //Green off
      bluVal = 256 - potVal; //Blue from full to off
  }
    Serial.println(potVal);
      analogWrite(red, redVal); //Write less values to LED pins
    analogWrite(green, grnVal);
    analogWrite(blue, bluVal);
  }


  //(potenti/1023) = (brightness/255)
  //Serial.println(analogRead(POTENTI_PIN));
  //double potenti = analogRead(POTENTI_PIN);
  //double divsi = (potenti/1023);
  //int brightness = divsi*255;
  //Serial.println("brightness");
 // Serial.println(brightness);
  //analogWrite(YELLOW_PIN, brightness);

  

    //  Serial.println(digitalRead(BUTTON));


{
    //  Serial.println(digitalRead(BUTTON));

if(Serial.available() > 0){
  String color = "red";
  color = Serial.readString();
if(color.startsWith("yellow")){
  digitalWrite(YELLOW_PIN, HIGH);
}
else{
  Serial.println("yellow didn't work");
}
if(color.startsWith("red")){
  digitalWrite(RED_PIN, HIGH);
}
  else{
    Serial.println("red didn't work");
}
if(color.startsWith("green")){
  digitalWrite(GREEN_PIN, HIGH);
}
  else{
    Serial.println("green didn't work");
}
}
//   //green light
if(digitalRead(BUTTON) == 2){
digitalWrite(GREEN_PIN, HIGH);
Serial.println("hello");
} else {
digitalWrite(GREEN_PIN, LOW);
}
}
}




//   //green light
//   if(digitalRead(BUTTON) == 1){
//     digitalWrite(GREEN_PIN, LOW);
//           Serial.println("hello");


//   } else {
//         digitalWrite(GREEN_PIN, HIGH);

//   } 
//     //  digitalWrite(GREEN_PIN, HIGH);

// delay(100);
  /*delay(1000);
  digitalWrite(GREEN_PIN, LOW);
  delay(0);
  */
  
  //yellow light
  // digitalWrite(YELLOW_PIN, HIGH);
  // delay(1000);
  // digitalWrite(YELLOW_PIN, LOW);
  // delay(0);
  
  // //red light
  // digitalWrite(RED_PIN, HIGH);
  // delay(1000);
  // digitalWrite(RED_PIN, LOW);
  // delay(0);
