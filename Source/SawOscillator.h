/*
  ==============================================================================

    SawOscillator.h
    Created: 31 May 2025 5:42:38pm
    Author:  Ngide

  ==============================================================================
*/

#pragma once

class SawOsc 
{
public: 
    float amp;
    float inc;
    float phase;

    void reset() {
        phase = 0.0f;
    }

    void noteOn(float amplitude, float increment) {
        amp = amplitude;
        inc = increment;
        reset();
    }

    float nextSample()
    {
        phase += inc;
        if (phase >= 1.0f) {
            phase -= 1.0f;
        }
        return amp * (2.0f * phase - 1.0f);
    }
};