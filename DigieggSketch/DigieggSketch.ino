#include <SPI.h>
#include <STBLE.h>
#include <Wire.h>
#include <BMA250.h>

#define USE_ABSOLUTE_ACCEL true
#define SAMPLE_DURATION (1000*30)
#define SAMPLE_INTERVAL 25

//Debug output adds extra flash and memory requirements!
#ifndef BLE_DEBUG
#define BLE_DEBUG false
#endif

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif


uint8_t ble_rx_buffer[21];
uint8_t ble_rx_buffer_len = 0;
uint8_t ble_connection_state = false;
#define PIPE_UART_OVER_BTLE_UART_TX_TX 0

#if defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#else
#define SerialMonitorInterface Serial
#endif

BMA250 accel;


void setup() {
  // Interface setup
  //SerialMonitorInterface.begin(9600);
  SerialMonitorInterface.begin(115200);
  while (!SerialMonitorInterface); //This line will block until a serial monitor is opened with TinyScreen+!
  // Accelerometer setup
  Wire.begin();
  accel.begin(BMA250_range_2g, BMA250_update_time_64ms);//This sets up the BMA250 accelerometer
  // Blue Tooth setup
  BLEsetup();
}

void loop() {
  // Blue tooth loop
  aci_loop();//Process any ACI commands or events from the NRF8001- main BLE handler, must run often. Keep main loop short.
  
  // Receive
  if (ble_rx_buffer_len) {//Check if data is available

    //accel.read();//This function gets new data from the accelerometer
    
    SerialMonitorInterface.print(ble_rx_buffer_len);
    SerialMonitorInterface.print(" : ");
    SerialMonitorInterface.println((char*)ble_rx_buffer);

    for (int i = 0; i < (SAMPLE_DURATION/SAMPLE_INTERVAL); i++) {
      accel.read();//This function gets new data from the accelerometer
      float x = (float)accel.X;
      float y = (float)accel.Y;
      float z = (float)accel.Z;

      // Create message from data
      String msg;
      if (USE_ABSOLUTE_ACCEL) {
        SerialMonitorInterface.print("abs accel:");
        SerialMonitorInterface.println(x*x);
        SerialMonitorInterface.println(y*y);
        SerialMonitorInterface.println(z*z);
        SerialMonitorInterface.println(sqrt(x*x + y*y + z*z));
        int abs_accel = (int)sqrt(x*x + y*y + z*z);
        msg = String(abs_accel);
      } else {
        msg = String(accel.X);
        msg += ",";
        msg += String(accel.Y);
        msg += ",";
        msg += String(accel.Z);
        // msg += ",";
        // msg += String(accel.rawTemp);
      }
      msg += '\n';
      msg += '\0';
    
      uint8_t sendBuffer[15];
      uint8_t sendLength = 15;

      if ((msg.length() + 1) < sendLength) {

        SerialMonitorInterface.print("Sending ");
        SerialMonitorInterface.print(msg.length());
        SerialMonitorInterface.print(" bytes for entry ");
        SerialMonitorInterface.println(i);
        
        msg.getBytes(sendBuffer, msg.length());
        sendBuffer[msg.length()] = '\0';

        lib_aci_send_data(PIPE_UART_OVER_BTLE_UART_TX_TX, sendBuffer, msg.length());

      } else {
        SerialMonitorInterface.print("Cannot send message of length ");
        SerialMonitorInterface.println(msg.length());
      }

      ble_rx_buffer_len = 0;//clear afer reading
      delay(SAMPLE_INTERVAL);
    }
  }

  
  // delay(250);//We'll make sure we're over the 64ms update time set on the BMA250
}
