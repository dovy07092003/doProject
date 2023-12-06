/*
File name: toggle.cpp (copy from textbox_LED.cpp)
Written by Amer Qouneh on November 11, 2023.
Works with Adafruit IO. Dashboard name: control LED.
A textbox on Adafruit IO allows a user to type the
number of times the LED on BBB will blink.

Program is based on subscribe.cpp by Derek Molloy.
Run: ./toggle
*/


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "MQTTClient.h"
#include "GPIO.h"

using namespace std;
using namespace exploringBB;

#define ADDRESS     "tcp://io.adafruit.com:1883"
#define CLIENTID    "Beagle5"
#define TOPIC       "dovy07092003/feeds/beaglebone-project.toggle"
#define AUTHMETHOD  "dovy07092003"
#define AUTHTOKEN   "aio_oGBk65x4zV6K7KrvYbDvTgHio9Sl"
#define QOS         1
#define TIMEOUT     10000L

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt) {
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    int i;
    char* payloadptr;
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");
    payloadptr = (char*) message->payload;
    //cout << "Printing payloadptr: " << payloadptr << endl;

    // Create a string named payload.
    string payload(payloadptr);
    cout<<"Toggle status is "<< payload<<endl;
    string tog_sta = payload;
    GPIO led_pin(48);// (pin p9.15)
    led_pin.setDirection(OUTPUT);
    if (tog_sta == "ON")
    {
	cout<<"Toggle status is ON, turn on the led"<<endl;
    	led_pin.setValue(HIGH);
    }    
    else
    {
	cout<<"Toggle status is OFF, turn off the led"<<endl;
	led_pin.setValue(LOW);
    }
    
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause) {
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[]) {
    MQTTClient client;
    MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    opts.keepAliveInterval = 20;
    opts.cleansession = 1;
    opts.username = AUTHMETHOD;
    opts.password = AUTHTOKEN;
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(client, &opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
    MQTTClient_subscribe(client, TOPIC, QOS);

    do {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}

