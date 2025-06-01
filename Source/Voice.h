/*
  ==============================================================================

    Voice.h
    Created: 24 May 2025 4:05:51pm
    Author:  Nick Gideo

  ==============================================================================
*/

#pragma once

#include "SawOscillator.h"

struct Voice
{
    int note;
    SawOsc osc;

    void reset() {
        note = 0;
        osc.reset();
    }

    float render() {
        return osc.nextSample();
    }


    void noteOn(int newNote, int velocity, float sampleRate) {
        note = newNote;

        float freq = 440.0f * std::exp2(float(note - 69) / 12.0f);

        float amp = (velocity / 127.0f) * 0.5f;
        float inc = freq / sampleRate;

        osc.noteOn(amp, inc);
    }
};