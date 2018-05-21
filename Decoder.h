#pragma once

#include "MIDI.h"
#include <cstdint>
#include <vector>

class Decoder
{
public:
	Decoder();
	~Decoder();

	void SetMIDIBuffer(std::vector<uint8_t>& buffer);
	void SetMIDIBuffer(std::string filename);
	MIDI GetMIDI();

	void RemoveMIDI();

	
private:
	std::vector<uint8_t> MIDIBuffer;

	bool containsMIDI = false;
};

