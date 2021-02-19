// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

#define VERDE 7
#define AMBAR 8
#define ROJO 9
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
 
  float oldTemp;
  float tempC;
  
void setup(void)
{
  // start serial port
  Serial.begin(57600);
  pinMode(VERDE,OUTPUT);
  pinMode(AMBAR,OUTPUT);
  pinMode(ROJO,OUTPUT);
  
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  pinMode(2,INPUT_PULLUP);
  sensors.begin();
  sensors.setResolution(10);
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  tempC = sensors.getTempCByIndex(0);
  oldTemp=tempC;

}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);


  if(tempC>=3.0 && tempC<=7.0){
    clearleds();
  digitalWrite(VERDE,HIGH);
    }
    else if(((tempC>=2.0)&&(tempC <= 3.0)) ||((tempC>7.0)&&(tempC<=8.0))){
    clearleds();
    digitalWrite(AMBAR,HIGH);
    }
    else
    {
      clearleds();
      digitalWrite(ROJO,HIGH);
      }
  

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    if(tempC!=oldTemp){
    Serial.print("Temperatura: ");
    Serial.println(tempC);}
    delay(1000);
  } 
  else
  {
    //Serial.println("Error: Skipping dataread");
  }

  oldTemp=tempC;
}

void clearleds(){
  digitalWrite(ROJO,LOW);
  digitalWrite(AMBAR,LOW);
  digitalWrite(VERDE,LOW);
  
  }
