/*
 * Note.h
 *
 *  An interrupt driven system for playing
 *  a single continuous note
 */
#ifndef SOURCES_NOTE_H_
#define SOURCES_NOTE_H_

#include <stdint.h>

static constexpr unsigned MIN_FREQUENCY=10;

static constexpr unsigned MAX_FREQUENCY=10000;




/**
 * Initialise the note playing system before first use
 */
void initialiseNotes(void);

/**
 * Changes the frequency of the note being played
 *
 * @param frequency - Frequency of note (100Hz-10kHz)
 *
 * @note This function returns immediately.
 *       The note is played by interrupt driven code.
 */
void setNoteFrequency(uint16_t frequency);

#endif
/* SOURCES_NOTES_H_ */
