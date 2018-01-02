#include <Bridge.h>
#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeSSLClient.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

#include <Wire.h>
 
 
void setup()
{
  Bridge.begin();
  Console.begin(); 

  while (!Console); 

  Console.println("\nI2C Scanner\nI2C Scanner");
  
  
        // Leonardo: wait for serial monitor
  //Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;
  int nDevices;
 
  Console.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Console.print("I2C device found at address 0x");
      if (address<16)
        Console.print("0");
      Console.print(address,HEX);
      Console.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Console.print("Unknown error at address 0x");
      if (address<16)
        Console.print("0");
      Console.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Console.println("No I2C devices found\n");
  else
    Console.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}
