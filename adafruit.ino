#include <DHT.h>                   // Data ---> D3 VCC ---> 3V3 GND ---> GND
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12,14); 
#define DHTType DHT11
// WiFi parameters
#define WLAN_SSID       "Project"
#define WLAN_PASS       "11111111"
// Adafruit IO
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Project"
#define AIO_KEY         "aio_EbTe60Yre3jzl8O4e"
WiFiClient client;
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");
Adafruit_MQTT_Publish Heart1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Heart1");
Adafruit_MQTT_Publish liveupdate = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/liveupdate");
//Adafruit_MQTT_Publish Humidity1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Humidity1");

//#define Type DHT11
//int DHT11PIN=2;
DHT dht(5,DHTType);
//float Humidity;
float tempC;
int Pulse=A0;
int Pulse_var;
String inputString="";

void setup() {
  pinMode(Pulse,INPUT);
//pinMode(DHT11PIN,INPUT);
  dht.begin();
  Serial.begin(115200);
  mySerial.begin(9600);
  Serial.println(F("Adafruit IO Example"));
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  delay(10);
  Serial.print(F("Connecting to "));
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());

  // connect to adafruit io
  connect();

}

// connect to adafruit io via MQTT
void connect() {
  Serial.print(F("Connecting to Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}

void loop() {
  // ping adafruit io a few times to make sure we remain connected
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }
  Pulse_var=analogRead(Pulse);
  Serial.print("Pulsevalue:");
  Serial.println(Pulse_var);
  delay(5000);
      tempC=dht.readTemperature();
    Serial.print("Temperature:");
    Serial.print(tempC);
    Serial.println(" c ");
    delay(1000);
  //  Temperature1->save(tempC);
    delay(5000);
     if(mySerial.available())
  {  
    //Serial.print("HI");
    inputString=mySerial.readString();
    Serial.println(inputString);
  //  liveupdate->save(inputString);

      
  }
    Serial.println(inputString);
//   liveupdate ->save("welcome");
    delay(5000);
    
  



  String one = "PACKAGE LOCATION AT:https://www.google.com/maps/?q=";
String two = "," ;   
String message = one +"latitude" +two + "longitude";

int str_len = message.length() + 1;
char textmessage[str_len];
message.toCharArray(textmessage,str_len);

    delay(500);

   if (! temperature.publish(tempC)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    } 
      if (! Heart1.publish(Pulse_var)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    } 
      if (! liveupdate.publish(textmessage)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    } 
    else {
      Serial.println(F("Sent!"));
    }
}
