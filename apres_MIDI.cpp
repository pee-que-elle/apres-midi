// apres_MIDI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Decoder.h"

int main()
{
	auto d = Decoder();
	d.SetMIDIBuffer("C:\\Users\\david\\Downloads\\Fagning.mid");

	MIDI a = d.GetMIDI();

	system("pause");
	
    return 0;
}

