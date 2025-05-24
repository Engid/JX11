/*
  ==============================================================================

    Voice.h
    Created: 24 May 2025 4:05:51pm
    Author:  Nick Gideo

  ==============================================================================
*/

#pragma once

struct Voice
{
    int note;
    int velocity;

    void reset() {
        note = 0;
        velocity = 0;
    }
};