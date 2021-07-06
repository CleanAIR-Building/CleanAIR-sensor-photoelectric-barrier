#include "PhotoelectricBarrier.h"
#include "CleanAIRDevice.h"

PhotoelectricBarrier::PhotoelectricBarrier()
{
    Serial.println("PhotoelectricBarrier setup now...");

    pinToRead = D0;
    lastState = PhotoelectricBarrier::STATE::NOT_RECOGNIZED;
    pinMode(pinToRead, INPUT);

    Serial.println("PhotoelectricBarrier successfully set up!");
}

void PhotoelectricBarrier::Loop()
{
    int readValue = digitalRead(pinToRead);

    if (readValue == LOW)
    {
        // Object present
        if (lastState == PhotoelectricBarrier::STATE::NOT_RECOGNIZED)
        {
            Serial.println("Object detected");
            lastState = PhotoelectricBarrier::STATE::RECOGNIZED;
            Publish(CleanAIR::GetConfig().mqttPublishTopic.c_str(), CreateMessage(lastState));
        }
    }
    else
    {
        // Object gone
        if (lastState == PhotoelectricBarrier::STATE::RECOGNIZED)
        {
            lastState = PhotoelectricBarrier::STATE::NOT_RECOGNIZED;
            Serial.println("Object is gone ;)");
            Publish(CleanAIR::GetConfig().mqttPublishTopic.c_str(), CreateMessage(lastState));
        }
    }
}

CleanAIR::MessageJson PhotoelectricBarrier::CreateMessage(const PhotoelectricBarrier::STATE newState)
{
    CleanAIR::MessageJson message;
    message["sensor"] = CleanAIR::GetConfig().mqttClientName.c_str();
    message["barrier"] = (newState == PhotoelectricBarrier::STATE::RECOGNIZED) ? "1" : "0";
    return message;
}
