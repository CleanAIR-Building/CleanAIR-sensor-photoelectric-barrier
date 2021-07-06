#pragma once
#include "MessageProducer.h"

class PhotoelectricBarrier : public CleanAIR::MessageProducer
{
public:
    enum class STATE
    {
        RECOGNIZED,
        NOT_RECOGNIZED
    };
    PhotoelectricBarrier();
    virtual void Loop() override;

private:
    int pinToRead;
    STATE lastState;
    CleanAIR::MessageJson CreateMessage(STATE newState);
};