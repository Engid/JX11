/*
  ==============================================================================

    Oscillator.h
    Created: 25 May 2025 12:56:57pm
    Author:  Ngideo

  ==============================================================================
*/

#pragma once

#include <cmath>

const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
public: 
    float amp;
    float freq;
    float sampleRate;
    float phaseOffset;
    int sampleIndex;
    
    void reset() { sampleIndex = 0; }

    float nextSample() {
        float output = amp * std::sin(TWO_PI * sampleIndex * freq / sampleRate + phaseOffset);
        sampleIndex += 1;

        return output;
    }

};