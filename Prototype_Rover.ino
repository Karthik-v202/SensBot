// Include the library files
#define BLYNK_TEMPLATE_ID "TMPLsbAvPX1P"
#define BLYNK_DEVICE_NAME "Prototype"
#define BLYNK_AUTH_TOKEN "4L1qUPr6q3lzFXsPIuHS4OZa3WwNvLpk"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>


// Define the motor pins
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4



// Variables for the Blynk widget values
int x = 50;
int y = 50;

char auth[] = "4L1qUPr6q3lzFXsPIuHS4OZa3WwNvLpk"; //Enter your Blynk auth token
char ssid[] = "Suresh @ MAK NET"; //Enter your WIFI name
char pass[] = "password@123"; //Enter your WIFI passowrd
int smokeA0 = A0;
int data = 0;
int sensorThres = 0;


const int led = D7;
const int proximityPin = D6;

#define DHTPIN 14          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);


BlynkTimer timer;

void sendSensor(){
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 int data = analogRead(smokeA0);
 int proximityValue = digitalRead(proximityPin);
 Blynk.virtualWrite(V3, data);
  Serial.print("Pin A0: ");
  Serial.println(data);
   Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V7, proximityValue);
  Blynk.virtualWrite(V8,led)


   if(data > 20);     // Change the Trashold value
  {
    Blynk.email("karthikvsuresh06@gmail.com", "Alert", "High level of gas detected !");
    Blynk.logEvent("High level of gas detected","High level of gas detected");
  }
}

void setup() {
   pinMode(proximityPin, INPUT);
 pinMode(led, OUTPUT);
  digitalWrite(led, LOW);   
   pinMode(smokeA0, INPUT);
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);
   dht.begin();
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
  //Set the motor pins as output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  x = param[0].asInt();
}
// Get the joystick values
BLYNK_WRITE(V1) {
  y = param[0].asInt();
}
BLYNK_WRITE(V8)
{
  int pinValue = param.asInt();
  if (pinValue == 1)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}

// Check these values using the IF condition
void smartcar() {
  if (y > 70) {
    carForward();
    Serial.println("carForward");
  } else if (y < 30) {
    carBackward();
    Serial.println("carBackward");
  } else if (x < 30) {
    carLeft();
    Serial.println("carLeft");
  } else if (x > 70) {
    carRight();
    Serial.println("carRight");
  } else if (x < 70 && x > 30 && y < 70 && y > 30) {
    carStop();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
  timer.run();
}

/**************Motor movement functions*****************/
void carForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}