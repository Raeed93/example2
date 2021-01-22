#include <Tune.h>
#include <pit.h>
#include "hardware.h"
#include <Note.h>
using namespace USBDM;
using Timer		  	= Pit;
using TimerChannel	= Timer::Channel<0>;
static constexpr int C7=2093;
static constexpr int D7=2349;
static constexpr int E7=2489;
static constexpr int F7=2794;
static constexpr int G7=3136;
static constexpr int A7=3520;
static constexpr int B7=3951;
static constexpr int C6=C7/2;
static constexpr int D6=D7/2;
static constexpr int E6=E7/2;
static constexpr int F6=F7/2;
static constexpr int G6=G7/2;
static constexpr int A6=A7/2;
static constexpr int B6=B7/2;
static constexpr int STOP=1;
int i=0;
float BaseDuration=100*ms;
int flag;
//............................./

struct NoteData{
int frequency;
int duration;
};
static NoteData NoteTable[]={{C6,1}, {E6,1}, {F6,2}, {G6,4},
		{G6,1}, {C6,1}, {E6,1}, {F6,1}, {G6,4},
		{G6,1}, {C6,1}, {E6,1}, {F6,1}, {G6,2}, {E6,2},
		{C6,2}, {E6,2}, {D6,4},
		{D6,1}, {E6,1}, {E6,1}, {D6,1}, {C6,3}, {C6,1},
		{E6,2}, {G6,2}, {G6,1}, {F6,3},
		{F6,2}, {E6,1}, {F6,1}, {G6,2}, {E6,2},
		{C6,2}, {D6,2}, {C6,4},
		{C6,1},{STOP,0}};

void startTune(float time)
{
Timer::configure(PitDebugMode_Stop);
TimerChannel::setCallback(PitCallback);
TimerChannel::configure(time, PitChannelIrq_Enabled);
TimerChannel ::enableNvicInterrupts(NvicPriority_Normal);
initialiseNotes();
}
void stopTune()
{
	TimerChannel::configure(PitChannelIrq_Disabled);

}

void playTuneOnce(){
	startTune(100*ms);
	flag=1;


};
void PitCallback(void)
{
	if(NoteTable[i].frequency==STOP)
	{
		if(flag)
			stopTune();
		else
			i=0;
	}
	if(NoteTable[i].duration==0)
		i++;
	setNoteFrequency(NoteTable[i].frequency);
	NoteTable[i].duration--;

}
