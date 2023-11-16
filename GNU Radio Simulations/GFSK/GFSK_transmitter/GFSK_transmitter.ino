#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // Set CE and CSN pins

void setup() {
  radio.begin();
  radio.openWritingPipe(0xF0F0F0E1LL);  // Set the transmit pipe address
  radio.setPALevel(RF24_PA_HIGH);       // Set the power level to high
  radio.setDataRate(RF24_1MBPS);        // Set the data rate
  radio.setChannel(76);                 // Set the channel

  // Optionally configure other settings like CRC, retry, etc.
}

void loop() {
  // Create a data packet to send (GFSK-modulated)
  // You need to implement the GFSK modulation yourself, which is more complex.

  // Send the data packet
  if (radio.write(&data_packet, sizeof(data_packet))) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Data transmission failed");
  }

  delay(1000);  // Delay between transmissions
}
