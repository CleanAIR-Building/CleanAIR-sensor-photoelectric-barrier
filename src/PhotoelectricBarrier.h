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
    PhotoelectricBarrier(bool isEntrance);
    virtual void Loop() override;

private:
    int pinToRead;
    bool isEntrance;
    STATE lastState;
    CleanAIR::MessageJson CreateMessage(STATE newState);
};