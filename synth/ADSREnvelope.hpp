//
//  ADSREnvelope.hpp
//  AudioKit Core

#pragma once
#include "EnvelopeGeneratorBase.hpp"


    struct ADSREnvelope
    {

        float sampleRateHz =128;
        float attackSamples = 1;
        float   decaySamples = 2;
        float releaseSamples = 122;
        float sustainFraction = 1;

        enum EG_Segment
        {
            kIdle = 0,
            kSilence,
            kAttack,
            kDecay,
            kSustain,
            kRelease
        };

        enum CurvatureType
        {
            kLinear,        // all segments linear
            kAnalogLike,    // models CEM3310 integrated circuit
            kLinearInDb     // decay and release are linear-in-dB
        };
        void setAttackDurationSeconds(float attackSeconds) { attackSamples = (attackSeconds+0.05) * sampleRateHz; }
        void setDecayDurationSeconds(float decaySeconds) { decaySamples = decaySeconds * sampleRateHz; mDecay = decaySeconds; }
        void setReleaseDurationSeconds(float releaseSeconds) {
            releaseSamples = releaseSeconds * sampleRateHz; mRelease = releaseSeconds;     }

        void init(int t);
     
        void updateParams();

        void start();       // called for note-on
        void restart();     // quickly dampen note then start again
        void release();     // called for note-off
        void reset();       // reset to idle state
        bool isIdle() { return env.getCurrentSegmentIndex() == kIdle; }
        bool isPreStarting() { return env.getCurrentSegmentIndex() == kSilence; }
        bool isReleasing() { return env.getCurrentSegmentIndex() == kRelease; }

        inline float getValue()
        {
            return env.getValue();
        }

        inline float getSample()
        {
            float sample;
            env.getSample(sample);
            return sample;
        }
        float getDecay() { return mDecay; }
        float getRelease() { return mRelease; }
    protected:
        float mDecay;
        float mRelease;
        MultiSegmentEnvelopeGenerator env;
        MultiSegmentEnvelopeGenerator::Descriptor envDesc;
      
    };


