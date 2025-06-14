/*
  ==============================================================================

    Utils.h
    Created: 25 May 2025 2:13:58am
    Author:  Ngideo

  ==============================================================================
*/

#pragma once

#include <cmath>
#include <JuceHeader.h>

inline void protectYourEars(float* buffer, int sampleCount) 
{
    if (buffer == nullptr) { return; }

    bool firstWarning = true;

    for (int i = 0; i < sampleCount; ++i) {
        float x = buffer[i];
        bool silence = false;

        if (std::isnan(x)) {
            DBG("!!! WARNING: nan detected in audio buffer; Silencing!");
            silence = true;
        }
        else if (std::isinf(x)) {
            DBG("!!! WARNING: inf detected in audio buffer; Silencing!");
            silence = true;
        }
        else if (x < -2.0f || x > 2.0f) {
            DBG("!!! WARNING: sample out of range; Silencing");
            silence = true;
        }
        else if (x < -1.0f) {
            if (firstWarning) {
                DBG("!!! WARNING: sample out of range; clamping!");
                firstWarning = false;
            }
            buffer[i] = -1.0f;
        }
        else if (x > 1.0f) {
            if (firstWarning) {
                DBG("!!! WARNING: sample out of range; clamping!");
                firstWarning = false;
            }
            buffer[i] = 1.0f;
        }

        if (silence) {
            memset(buffer, 0, sampleCount * sizeof(float));
            return;
        }
    }
}