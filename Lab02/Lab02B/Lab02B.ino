#include "Lab02B.h"

void setup() {
  Serial.begin(9600);
  Serial.print("\n\n------------------------\n"
    + groupName + " : " + deviceName + "\n------------------------\n\n"); 
  
  Wire.begin();
  Wire.beginTransmission(ADDR);
  Wire.endTransmission();
  delay(300);

  lightSensor.begin(aGain, aTime);

  SerialBT.begin(groupName + " : " + deviceName); 
  Serial.println("Ready for bluetooth connection!");
  
}

void loop() {
    
  //Temp sensor
  Wire.beginTransmission(ADDR);
  Wire.write(TMP_CMD);
  Wire.endTransmission();
  delay(100);

  Wire.requestFrom(ADDR, 2);

  char data[2];
  if(Wire.available() == 2){
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  float temp = ((data[0] * 256.0) + data[1]);
  float tempC = ((175.72 * temp) / 65536.0) - 46.85;
  Serial.println("Temperature: " + String(tempC) + " degC");

  //Humidity sensor
  Wire.beginTransmission(ADDR);
  Wire.write(HUM_CMD);
  Wire.endTransmission();
  delay(100);
  
  Wire.requestFrom(ADDR, 2);

  char Data[2];
  if(Wire.available() == 2){
    Data[0] = Wire.read();
    Data[1] = Wire.read();
  }

  float raw_humidity = ((Data[0] * 256.0) + Data[1]);
  float humidity = ((125 * raw_humidity)/65536.0) - 6;
  Serial.println("Humidity: " + String(humidity) + "%");

  //Sample light sensor
  AsyncAPDS9306Data lightData = lightSensor.syncLuminosityMeasurement();
  
  //Calculate luminosity
  float lux = lightData.calculateLux();
  Serial.println("Luminosity: " + String(lux) + " Lux");


  //Format data as a JSON string
  String sendData = "{ \"" + groupName + "\": { \"" + deviceName + "\": { \"Temp\": \"" 
      + String(tempC) + "\", \"Humidity\":\"" + String(humidity)+ "\", \"Luminosity\": \"" + String(lux) + "\" } } }" + '\n';
      
  Serial.println("Prepared bluetooth message: " + sendData);
  
  //Push the string characters onto the bluetooth output buffer
  for (int i = 0; i < strlen(sendData.c_str()) + 1; i++){
    SerialBT.write(sendData.c_str()[i]);
  }

  delay(500);
  Serial.println("Bluetooth sent!");
  
  delay(DELAY_BETWEEN_SAMPLES_MS);

}
