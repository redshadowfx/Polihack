// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

char checkByte;
char* numberOfRoomsC;
int numberOfRoomsI = 0;

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  //Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

  /*while(Serial.available()==0);
    numberOfRoomsC = Serial.read();
    //Serial.println(numberOfRoomsC);
    for(int i = 0; i < sizeof(numberOfRoomsC)/sizeof(char); i++){
      numberOfRoomsI *= 10;
      numberOfRoomsI += (int)(numberOfRoomsC[i] - '0');
    }*/
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  //if(sensors.isConnected(0)){
    // call sensors.requestTemperatures() to issue a global temperature 
    // request to all devices on the bus
    //Serial.print("Requesting temperatures...");
    sensors.requestTemperatures(); // Send the command to get temperatures
    //Serial.println("DONE");
    // After we got the temperatures, we can print them here.
    // We use the function ByIndex, and as an example get the temperature from the first sensor only.
    /*Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(sensors.getTempCByIndex(0));
    Serial.print("Temperature for the device 2 (index 1) is: ");
    Serial.println(sensors.getTempCByIndex(1)); */
    
    for(int i = 0; i < /*numberOfRoomsI*/ 50; i++){
      while(Serial.available()==0);
      checkByte = Serial.read();
      //Serial.read();
      if(i < 10)
        Serial.print("00");
      else if(i >= 10 && i < 99)
        Serial.print('0');
      Serial.print(i);
      Serial.print(' ');
      if(sensors.getTempCByIndex(i) > 0)
        Serial.print(sensors.getTempCByIndex(i));
      else
        Serial.print(99.00);  
      Serial.print('\n');
      //Serial.print(" *#\n");
    delay(10);     
    }
  //}
  //else
    //Serial.println("Sensor not connected!");
}
