#include "hardware.h"
#include <Tune.h>
#include <Note.h>

// Allow acpit.hcess to USBDM methods without USBDM:: prefix
using namespace USBDM;
using Adc=Adc0;
using AdcChannel= Adc::Channel<14>;


void initADC(void);


void initADC(void){
	Adc::configure(AdcResolution_10bit_se,AdcClockSource_Bus);

	Adc::calibrate();

	Adc::setAveraging(AdcAveraging_4);

	AdcChannel ::setInput();
}

int main() {

	initADC();



	//startTune(100*ms);
   for(;;) {
	   uint16_t val=AdcChannel::readAnalogue();
if(val<50)
	playTuneOnce();



   }
   return 0;
}
