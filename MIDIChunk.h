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

	virtual std::string Info();

	size_t GetDataLength();
	std::string GetType();
	MIDIType type;
	std::vector<uint8_t> data;
	
};

