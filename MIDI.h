#pragma once

#include "MIDIChunk.h"
#include <vector>


class MIDI
{
public:
	MIDI();
	~MIDI();

	void AddChunk(MIDIChunk *chunk);
	void PrintInfo();

	std::vector<MIDIChunk*> chunks;

private:
	size_t chunks_parsed = 0;


};
