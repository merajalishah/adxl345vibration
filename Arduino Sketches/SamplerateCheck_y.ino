#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
  unsigned long cycletime=425;/*cycle time*/
  unsigned long timenow = 0;


Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void displaySensorDetails(void){
                               sensor_t sensor;
                               accel.getSensor(&sensor);
                               Wire.setClock(1000000);/*set Wire clock speed 1MHz*/
                               accel.setRange(ADXL345_RANGE_16_G);/*set +-16g range*/
                               accel.setDataRate(ADXL345_DATARATE_3200_HZ);/*set internal sample rate 3200Hz*/
                               }
void displayDataRate(void){}
void displayRange(void){}
void setup(void)  {
                  Serial.begin(2000000);
                  if(!accel.begin()){
                                    Serial.println("ADXL345 not detected");
                                    while(1);
                                    }
                  displaySensorDetails();
                  displayDataRate();
                  displayRange();
                  Serial.println("");
                  }
  
void loop(void) {
                 double t1 = micros();/*START time in microseconds*/
                 for (double i = 0; i <= 3000; i++){/*Acquire 30000 y-axis accleration readings from the sensor*/
                                                    Serial.println(accel.getY());
                                                    while(micros()< timenow + cycletime){}/*wait until cycletime is exceedes*/
                                                    timenow = micros();
                                                    }
                 double t2  = micros();/*END time in microseconds*/
                 double s= (3000000000)/(t2-t1);/*Calculate sample rate = (number of acquired samples i.e. 30000)/(elapsed time in seconds)*/
                 Serial.println("============================");
                 Serial.print("SAMPLE RATE (Hz) =  ");
                 Serial.println(s);/*display sample rate*/
                 Serial.println("============================");
                 delay(3000);
                 }
