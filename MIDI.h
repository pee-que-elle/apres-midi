#pragma once

#include "MIDIChunk.h"
#include <vector>


class MIDI
{
public:
	MIDI();
	~MIDI();

	void AddChunk(MIDIChunk *chunk);

	std::vector<MIDIChunk*> chunks;

	size_t chunks_parsed = 0;


};
