#pragma once

#include <string>
#include <vector>

#include "Helpers.h"

typedef enum MIDIType {HEADER = 0, TRACK=1 } MIDITYPE;

class MIDIChunk
{
public:
	MIDIChunk(MIDIType type, std::vector<uint8_t>& data);
	virtual ~MIDIChunk();

	size_t GetDataLength();
	std::string GetType();
	MIDIType type;
	std::vector<uint8_t> data;
	
};

