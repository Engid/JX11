/*
  ==============================================================================

    Voice.h
    Created: 24 May 2025 4:05:51pm
    Author:  Nick Gideo

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"

struct Voice
{
    int note;
    Oscillator osc;

    void reset() {
        note = 0;
        osc.reset();
    }

    float render() {
        return osc.nextSample();
    }
};