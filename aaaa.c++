/*
 * There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.
 * 
 * U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
 * U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
 * U2UXD is unused and can be used for your projects.
 *  34 rx   32TX
*/

// #define RXD2 19
// #define TXD2 18

#define RXD2 34
#define TXD2 32

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);


  Serial2.begin(9600, SERIAL_8E1, RXD2, TXD2);
  //Serial2.begin(38400);
  Serial.println("Serial Txd is on pin: "+String(TX));
  Serial.println("Serial Rxd is on pin: "+String(RX));
}

void loop() { //Choose Serial1 or Serial2 as required


// 1 3 1 2 0 4 228 53 1 3 8 0 0 0 0 0 0 0 0 149 215
// SOH ETX SOH STX NULL EOT 228 5 SOH ETX BS 00000000 149 215
// 122 0 0 0 0 0 0 0 0 2 0 0 0 0 1 0 0 0 0 0 248

/*
223 221 127 255 255 255 192 194 254 226 2 64 0 80 83 146 162 8 24 98 144 237 234 157 20 17 137 164 4 192 19 5 166 138 16 27 2 32 16 38 7 0 0 0 46 38 120 83 188 124 253 88 59 32 32 0 131 9 1 33 6 0 0 0 0 0 0 168 12 83 0 32 18 134 64 115 4 0 0 128 169 4 0 0 98 0 192 0 16 0 42 221 0 124 244 47 130 180 65 9 59 138 126 255 253 184 4 15 70 128 13 16 32 16 192 0 20 0 0 96 0 16 0 28 0 96 65 184 18 128 10 0 192
192 246 246 167 4 48 55 17 0 64 104 0 8 28 2 160 22 128 54 2 153 0 1 41 97 18 1 32 128 80 0 36 132 32 16 0 0 0 0 4 0 0 0 0
179 246 6

231 187 253 127 196 174 252 247 255 255 125 0 0 1 128 48 21 140 34 4 64 0 17 8 2 16 131 32 0 18 17 7 0 1 36 133 245 119 4 185 36 126 250 211 115 189 4 232 212 29 61 61 107 0 0
*/





  
  while (Serial2.available()) {
   // Serial.println(char(Serial2.read()));

  Serial.print(Serial2.read());
   Serial.print(" ");
    
  } Serial.println();


  //Serial2.print(200);
  delay(500);


  
}


/* Baud-rates available: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200, 256000, 512000, 962100
 *  standard 485 (38400, n , 8 , 1)
 *  protocollo MODBUS RTU mode
 *  Protocols available:
 * SERIAL_5N1   5-bit No parity 1 stop bit
 * SERIAL_6N1   6-bit No parity 1 stop bit
 * SERIAL_7N1   7-bit No parity 1 stop bit
 * SERIAL_8N1 (the default) 8-bit No parity 1 stop bit
 * SERIAL_5N2   5-bit No parity 2 stop bits 
 * SERIAL_6N2   6-bit No parity 2 stop bits
 * SERIAL_7N2   7-bit No parity 2 stop bits
 * SERIAL_8N2   8-bit No parity 2 stop bits 
 * SERIAL_5E1   5-bit Even parity 1 stop bit
 * SERIAL_6E1   6-bit Even parity 1 stop bit
 * SERIAL_7E1   7-bit Even parity 1 stop bit 
 * SERIAL_8E1   8-bit Even parity 1 stop bit 
 * SERIAL_5E2   5-bit Even parity 2 stop bit 
 * SERIAL_6E2   6-bit Even parity 2 stop bit 
 * SERIAL_7E2   7-bit Even parity 2 stop bit  
 * SERIAL_8E2   8-bit Even parity 2 stop bit  
 * SERIAL_5O1   5-bit Odd  parity 1 stop bit  
 * SERIAL_6O1   6-bit Odd  parity 1 stop bit   
 * SERIAL_7O1   7-bit Odd  parity 1 stop bit  
 * SERIAL_8O1   8-bit Odd  parity 1 stop bit   
 * SERIAL_5O2   5-bit Odd  parity 2 stop bit   
 * SERIAL_6O2   6-bit Odd  parity 2 stop bit    
 * SERIAL_7O2   7-bit Odd  parity 2 stop bit    
 * SERIAL_8O2   8-bit Odd  parity 2 stop bit    
*/






// ESP8266 SoftwareSerial
// https://circuits4you.com/2016/12/14/software-serial-esp8266/

// #include <SoftwareSerial.h>

// // pins Rx GPIO14 (D5) and Tx GPIO 12 (D6)



// #define encoder1pinA 35    //35 33        32 33 heron   34 rx   32TX
// #define encoder1pinB 33





// SoftwareSerial swSer(34, 32);  

// void setup() {
//   Serial.begin(115200);   //Initialize hardware serial with baudrate of 115200
//   swSer.begin(115200);    //Initialize software serial with baudrate of 115200
//   Serial.println("\nESP32 Software serial test started");
// }

// void loop() {
//   while (swSer.available() > 0) {  //wait for data at software serial
//     Serial.write(swSer.read()); //Send data recived from software serial to hardware serial    
//   }
//   while (Serial.available() > 0) { //wait for data at hardware serial
//     swSer.write(Serial.read());     //send data recived from hardware serial to software serial
//   }
// }
