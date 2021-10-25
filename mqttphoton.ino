// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

// This #include statement was automatically added by the Particle IDE.

#define DHTPIN D2    // what pin we're connected to
#define DHTTYPE DHT11

#include "MQTT.h"

const int sensorPin= A0;

float celsius;
  

	
void callback(char* topic, byte* payload, unsigned int length);

/**
 * if want to use IP address,
 * byte server[] = { XXX,XXX,XXX,XXX };
 * MQTT client(server, 1883, callback);
 * want to use domain name,
 * exp) iot.eclipse.org is Eclipse Open MQTT Broker: https://iot.eclipse.org/getting-started
 * MQTT client("mqtt.eclipse.org", 1883, callback);
 **/
MQTT client("192.168.0.13", 1884, callback);

// recieve message
void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;

    if (!strcmp(p, "RED"))
        RGB.color(255, 0, 0);
    else if (!strcmp(p, "GREEN"))
        RGB.color(0, 255, 0);
    else if (!strcmp(p, "BLUE"))
        RGB.color(0, 0, 255);
    else
        RGB.color(255, 255, 255);
    delay(1000);
}

int loopCount;

void setup() {
    
	//dht.begin();
    RGB.control(true);
    
    //connect to the server
    client.connect("sparkclient");
//	int h = dht.getHumidity();
//Read temperature as Celsius
//	int t = dht.getTempCelcius();
    //Publish/subscribe
    
}

void loop() {
    RGB.color(255, 0, 0);
    if (client.isConnected()){
        
        int value = analogRead(sensorPin);
        celsius = 195/1024;

        //(1.1 * value * 100.0)/1024.0; 
        client.publish("prueba/temperatura","29";
        client.publish("prueba/humedad","65";
        client.publish("prueba/hora",Time.timeStr());
        Particle.publish("temperature", String(celsius));
        
        client.subscribe("prueba/message");
        delay(5000);
        client.publish("prueba/temperatura","30";
        client.publish("prueba/humedad","63";
        client.publish("prueba/hora",Time.timeStr());
        Particle.publish("temperature", String(celsius));
        
        client.subscribe("prueba/message");
    }
}
