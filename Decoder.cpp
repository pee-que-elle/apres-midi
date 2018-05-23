#include "stdafx.h"
#include "Decoder.h"

#include <cstdint>
#include <cassert>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "Helpers.h"
#include "MIDI.h"
#include "HeaderChunk.h"
#include "TrackChunk.h"


Decoder::Decoder()
{
}


Decoder::~Decoder()
{
}

void Decoder::SetMIDIBuffer(std::vector<uint8_t>& buffer)
{

	Helpers::AssertWarn(this->containsMIDI, "MIDI already set");
	this->MIDIBuffer = buffer;

	this->containsMIDI = true;
}

void Decoder::SetMIDIBuffer(std::string filename)
{
	Helpers::AssertWarn(this->containsMIDI, "MIDI already set");
	std::ifstream file(filename, std::ios::binary);

	Helpers::AssertError(file.fail(), "Something went wrong opening \"" + filename + "\"");

	this->MIDIBuffer = std::vector<uint8_t>(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>()
	);

	this->containsMIDI = true;
}

MIDI Decoder::GetMIDI()
{
	std::vector<std::string> chunk_names = { "MThd", "MTrk" };

	auto mid = MIDI();
	for (unsigned i = 0; i < this->MIDIBuffer.size();)
	{
		
		// We can use a static offset because chunk names/chunk lengths are always 4 chars long
		auto chunk_header = std::string(this->MIDIBuffer.begin() + i, this->MIDIBuffer.begin() + i + 4); 
		i += 4;
		uint32_t length = Helpers::ParseMSBU32(&MIDIBuffer[i]);
		i += 4;
		
		// Be sure to prevent segfaults with bounds checking
		Helpers::AssertError(length > this->MIDIBuffer.size() - i, std::string("Length of " + std::to_string(length) + " Bytes exceeds buffer length."));

		// TODO just skip invalid names like the specification says
		Helpers::AssertError(std::find(chunk_names.begin(), chunk_names.end(), chunk_header) == chunk_names.end(), "Invalid chunk name detected: " + chunk_header);
		
		std::vector<uint8_t> data(
			this->MIDIBuffer.begin() + i - 8, 
			this->MIDIBuffer.begin() + i + length
		);

		if (chunk_header == "MThd") mid.AddChunk(HeaderChunk(data));
		else mid.AddChunk(TrackChunk(data));

		i += length;	
	}

	return mid;
}

void Decoder::RemoveMIDI()
{
	Helpers::AssertWarn(!this->containsMIDI, "Removing empty MIDI");

	this->MIDIBuffer = std::vector<uint8_t>();
	this->containsMIDI = false;
}
