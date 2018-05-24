#include "stdafx.h"
#include "MIDI.h"

#include <iomanip>
#include "HeaderChunk.h"
#include "TrackChunk.h"

MIDI::MIDI()
{
}

MIDI::~MIDI()
{
}

void MIDI::AddChunk(MIDIChunk *chunk)
{
	Helpers::AssertError(chunk->type == TRACK && this->chunks_parsed == 0, "Track chunk at faulty index.");
	Helpers::AssertError(chunk->type == HEADER && this->chunks_parsed != 0, "Header chunk at faulty index.");
	this->chunks.push_back(chunk);
	this->chunks_parsed++;
}

void MIDI::PrintInfo()
{
	for (int i = 0; i < this->chunks.size(); ++i)
	{
		MIDIChunk*& c = this->chunks[i];

		std::cout << "Chunk #" << i << ": " << std::endl;
		std::cout << "Type: " << (c->type == HEADER ? "Header" : "Track") << std::endl << std::endl;
		std::cout << std::setfill('-') << std::setw(100) << "" << std::endl;
		switch (c->type)
		{
		case HEADER:
			std::cout << dynamic_cast<HeaderChunk*>(c)->Info();
			break;
		case TRACK:
			std::cout << dynamic_cast<TrackChunk*>(c)->Info();
			break;
		}
		std::cout << std::setfill('-') << std::setw(100) << "" << std::endl;

		std::cout << std::endl << std::endl << std::endl;
	}
}
