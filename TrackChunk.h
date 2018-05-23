#pragma once

#include "MIDIChunk.h"
#include "TrackEvent.h"
#include <ctime>

class TrackChunk : public MIDIChunk
{
public:
	TrackChunk(std::vector<uint8_t>& data);
	~TrackChunk();
	
	std::vector<std::pair<uint32_t, TrackEvent>> pairs;

	void ParseEvents();


};

