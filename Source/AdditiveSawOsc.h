/*
  ==============================================================================

    AdditiveSawOsc.h
    Created: 1 Jun 2025 1:12:16am
    Author:  Ngide

  ==============================================================================
*/

#pragma once

class AdditiveSawOsc
{
public: 
    float amp;
    float inc;
    float phase;

    float freq;
    float sampleRate;
    float phaseBL;

    void noteOn(float amplitude, float increment) {
        amp = amplitude;
        inc = increment;
        reset();
    }

    void reset()
    {
        phase = 0.0f;
        phaseBL = -0.5f;
    }

    float nextBandLimitedSample() {
        phaseBL += inc;
        if (phaseBL >= 1.0f) {
            phaseBL -= 1.0f;
        }

        // todo..

    }
};