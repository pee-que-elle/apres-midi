// apres_MIDI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Decoder.h"
#include "HeaderChunk.h"
#include "TrackChunk.h"
#include <memory>

#include <iomanip>

int main()
{
	auto d = Decoder();
	d.SetMIDIBuffer("C:\\Users\\david\\Downloads\\Fagning.mid");

	MIDI a = d.GetMIDI();

	a.PrintInfo();

	system("pause");
	
    return 0;
}

