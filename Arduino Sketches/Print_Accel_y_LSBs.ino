#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
  unsigned long cycletime = 360;
  unsigned long timenow = 0;


Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void displaySensorDetails(void){
                               sensor_t sensor;
                               accel.getSensor(&sensor);
                               Wire.setClock(1000000);
                               accel.setRange(ADXL345_RANGE_16_G);
                               accel.setDataRate(ADXL345_DATARATE_3200_HZ);
                               }
void displayDataRate(void){}
void displayRange(void){}
void setup(void)  {
                  Serial.begin(2000000);
                  if(!accel.begin()){
                                    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
                                    while(1);
                                    }
                  displaySensorDetails();
                  displayDataRate();
                  displayRange();
                  Serial.println("");
                  }
  
void loop(void) {
                  Serial.println(accel.getY());
                  while(micros()< timenow + cycletime){}
                  timenow = micros();
                 }
