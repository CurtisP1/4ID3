
#include "Project.h"

const int REED_PIN[8] = {13, 25, 26, 32, 5, 4, 19, 18};
const int LED_PIN[6] = {27, 33, 12, 17, 16, 1};// LED pin
int proximity[8]={};

void setup() {
  Serial.begin(2000000);

    //Start the WiFi driver and tell it to connect to your local network
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to "); Serial.print(ssid);
  
  //While it is connecting, print a '.' to the serial monitor every 500 ms
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Once connected, print the local IP address
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //Set the MQTT client to connect to the desired broker
  client.setServer(mqtt_server, 1883);

  for (int i = 0; i<6; i++){
    pinMode(LED_PIN[i], OUTPUT); // Enable LED
  }
  
  for (int i = 0; i<8; i++){
    pinMode(REED_PIN[i], INPUT_PULLUP); // Enable internal pull-up for the reed switch
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESPClient")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  
  for (int i = 0; i<8; i++){
    proximity[i] = {digitalRead(REED_PIN[i])}; // Read the state of the switch
  }
  int count1 = 0;
  int count2 =0;

  if (!client.connected()) {
      reconnect();
    }
    client.loop();
  
  // If the pin reads low, the switch is closed.
  if (proximity[0] == LOW) {
    //Serial.println("Switch closed");   
    count1+=1;    
  }
  else {
    //Serial.println("Switch opened");   
  }
  
  if (proximity[1] == LOW) {
    //Serial.println("Switch closed");   
    count1+=1;    
  }
  else {
    //Serial.println("Switch opened");   
  }
  
    if (proximity[2] == LOW) {
    //Serial.println("Switch closed");   
    count2+=1;    
  }
  else {
    //Serial.println("Switch opened");   
  }
    if (proximity[3] == LOW) {
    //Serial.println("Switch closed"); 
    count2+=1;
  }
  else {
    //Serial.println("Switch opened");  
  }
  if (proximity[4] == LOW) {
    //Serial.println("Switch closed"); 
    count1+=1;
  }
  else {
    //Serial.println("Switch opened");  
  }
  if (proximity[5] == LOW) {
    //Serial.println("Switch closed"); 
    count1+=1;
  }
  else {
    //Serial.println("Switch opened");  
  }
  if (proximity[6] == LOW) {
    //Serial.println("Switch closed"); 
    count2+=1;
  }
  else {
    //Serial.println("Switch opened");  
  }
  if (proximity[7] == LOW) {
    //Serial.println("Switch closed"); 
    count2+=1;
  }
  else {
    //Serial.println("Switch opened");  
  }
  client.publish("4ID3_GroupCP/CarNS", String(count1).c_str());
  delay(100);
  client.publish("4ID3_GroupCP/CarEW", String(count2).c_str());

  if (count1>count2){
            
    if (digitalRead(LED_PIN[3]) == HIGH){
      digitalWrite(LED_PIN[3], LOW);
      digitalWrite(LED_PIN[4], HIGH);
      client.publish("4ID3_GroupCP/LightEW", "Yellow");
      delay(2000);
      digitalWrite(LED_PIN[4], LOW);
      digitalWrite(LED_PIN[5], HIGH);
      client.publish("4ID3_GroupCP/LightEW", "Red");
    }
    else{
      digitalWrite(LED_PIN[5], HIGH);
      client.publish("4ID3_GroupCP/LightEW", "Red");
    }
    digitalWrite(LED_PIN[2], LOW);
    digitalWrite(LED_PIN[1], LOW);
    digitalWrite(LED_PIN[0], HIGH);
    client.publish("4ID3_GroupCP/LightNS", "Green");
    
  }
  else if(count1==count2){
    
  }
  else {
    
    if (digitalRead(LED_PIN[0]) == HIGH){
      digitalWrite(LED_PIN[0], LOW);
      digitalWrite(LED_PIN[1], HIGH);
      client.publish("4ID3_GroupCP/LightNS", "Yellow");
      delay(2000);
      digitalWrite(LED_PIN[1], LOW);
      digitalWrite(LED_PIN[2], HIGH);
      client.publish("4ID3_GroupCP/LightNS", "Red");
    }
    else{
      digitalWrite(LED_PIN[2], HIGH);
      client.publish("4ID3_GroupCP/LightNS", "Red");
    }
    digitalWrite(LED_PIN[5], LOW);
    digitalWrite(LED_PIN[4], LOW);
    digitalWrite(LED_PIN[3], HIGH);
    client.publish("4ID3_GroupCP/LightEW", "Green");
  }

  
  delay(1000);
  count1 =0;
  count2 =0;
}
