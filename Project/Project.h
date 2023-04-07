#include <WiFi.h>
#include <PubSubClient.h>

//WiFi login credentials
char* ssid = "CURTIS-PC 9801";
char* pass = "4f7U5}85";
const char* mqtt_server = "test.mosquitto.org";
uint16_t addressPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
