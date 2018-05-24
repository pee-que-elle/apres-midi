#include "stdafx.h"
#include "MIDIChunk.h"

#include "Helpers.h"

#include <vector>
#include <cassert>

MIDIChunk::MIDIChunk(MIDITYPE type, std::vector<uint8_t>& data)
{
	this->type = type;
	this->data = data;

}

MIDIChunk::~MIDIChunk()
{
}

std::string MIDIChunk::Info()
{
	return std::string();
}

size_t MIDIChunk::GetDataLength()
{
	// Subtract 8 to account for the 4-byte size identifier and 4-byte chunk header 
	return this->data.size() - 4 - 4;
}

std::string MIDIChunk::GetType()
{
	return this->type == HEADER ? "Header" : "Track";
}
