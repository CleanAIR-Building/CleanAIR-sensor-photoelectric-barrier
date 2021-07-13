#include <Arduino.h>
#include "CleanAIRDevice.h"
#include "PhotoelectricBarrier.h"
#include "Definitions.h"

PhotoelectricBarrier photoelectricBarrier(true);

void setup()
{
  Serial.begin(BAUDRATE);
  CleanAIR::SetProducer(&photoelectricBarrier);
  CleanAIR::LoadConfiguration(CONFIG_FILE);
  CleanAIR::ConnectToWifi();
  CleanAIR::ConnectToMQTT();
  CleanAIR::InitializeHeartBeat(HEARTBEAT);
}

void loop()
{
  CleanAIR::Loop();
}