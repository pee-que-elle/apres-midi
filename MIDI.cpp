#include "stdafx.h"
#include "MIDI.h"


MIDI::MIDI()
{
}


MIDI::~MIDI()
{
}

void MIDI::AddChunk(MIDIChunk chunk)
{
	Helpers::AssertError(chunk.type == TRACK && this->chunks_parsed == 0, "Track chunk at faulty index.");
	Helpers::AssertError(chunk.type == HEADER && this->chunks_parsed != 0, "Header chunk at faulty index.");
	this->chunks.push_back(chunk);
	this->chunks_parsed++;
}
