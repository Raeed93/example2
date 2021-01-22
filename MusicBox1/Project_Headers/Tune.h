/*
 * Tune.h
 *
 *  Created on: 1Oct.,2017
 *      Author: podonoghue
 */

#ifndef SOURCES_TUNE_H_
#define SOURCES_TUNE_H_

/**
 * Start playing the tune
 */
void startTune(float time);

/**
 * Stop playing the tune
 */
void stopTune();

/**
 * Plays the entire tune once
 */
void playTuneOnce();
void PitCallback(void);

#endif /* SOURCES_TUNE_H_ */
