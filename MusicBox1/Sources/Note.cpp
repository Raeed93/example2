
#include "hardware.h"
#include <Note.h>

using namespace USBDM;

/**
 * This example uses FTM interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->FTM tab.
 * Select irqHandlingMethod option (Software (Use setCallback() or override class method)
 */

/**
 * Timer being used - change as required
 * Could also access as TimerChannel::Ftm
 */
using Timer = Ftm0;

/// Timer channel for output - change as required
using TimerChannel = Timer::Channel<6>;

/**
 * Half-period for timer in ticks.
 * This variable is shared with the interrupt routine
 */
static volatile uint16_t timerHalfPeriodInTicks;

/// Waveform period to generate

/// Maximum OC interval - the OC interval should not exceed this value.

/**
 * Interrupt handler for Timer interrupts
 * This sets the next interrupt/pin toggle for a half-period from the last event
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {

   // Check channel
   if (status & TimerChannel::CHANNEL_MASK) {

      TimerChannel::setDeltaEventTime(timerHalfPeriodInTicks);
   }
}

void initialiseNotes(void)
{


   Timer::configure(
         FtmMode_LeftAlign,       // Left-aligned is required for OC/IC
         FtmClockSource_System);  // Bus clock usually


   Timer::setMaximumInterval(1.1*0.5/MIN_FREQUENCY);

   setNoteFrequency(MIN_FREQUENCY);

   TimerChannel::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   Timer::enableNvicInterrupts(NvicPriority_Normal);


   TimerChannel::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);


   TimerChannel::setRelativeEventTime(10);

   TimerChannel::setChannelCallback(ftmCallback);

   TimerChannel::configure(
         FtmChMode_OutputCompareToggle, //  Output Compare with pin toggle
         FtmChannelAction_Irq);         //  + interrupts on events

   USBDM::checkError();
}

void setNoteFrequency(uint16_t frequency){
timerHalfPeriodInTicks = Timer::convertSecondsToTicks(0.5/frequency);
}


