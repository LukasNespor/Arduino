#include <VirtualWire.h>
 
void setup()
{
    Serial.begin(9600);          // Configure the serial connection to the computer
    vw_set_ptt_inverted(true);  // Required by the RF module
    vw_setup(2000);            // bps connection speed
    vw_set_rx_pin(2);         // Arduino pin to connect the receiver data pin
    vw_set_tx_pin(8);
    vw_rx_start();           // Start the receiver

    attachInterrupt(2, receive, RISING);
}
 
void loop()
{
  const char *msg = "Hello World";
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
  delay(200);
}

void receive()
{
  Serial.println("Receive");
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen))      // We check if we have received data
  {
    int i;
    // Message with proper check    
    for (i = 0; i < buflen; i++)
    {
      Serial.write(buf[i]);
    }
    Serial.println();
  }
}

