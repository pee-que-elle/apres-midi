#pragma once

#include "MIDIChunk.h"

enum DivisionType { TICKS_PER_QUARTER_NOTE = 0, FRAMES_PER_SECOND_TICKS_PER_FRAME = 1 };

class HeaderChunk : public MIDIChunk
{
public:
	HeaderChunk(std::vector<uint8_t>& data);
	~HeaderChunk();

	std::string Info() override;

	uint16_t format = 0; // Either 0, 1, or 2. 0=single track, 1=one or more simultaneous tracks, 2=one or more independent tracks
	uint16_t tracks = 0; // Amount of tracks in the MIDI
	uint16_t division = 0; // Default delta time unit for MIDI

	

	struct DivisionDetails
	{

		enum DivisionType type;

		/**/
		uint16_t delta_time_per_quarter = 0; // 15-bit value signifying the number of delta time units per quarter note. Only set if type==0
		/**/

		/**/
		uint8_t delta_time_per_SMTPE_frame = 0; // 8-bit number signifying the number of delta time units per SMTPE frame. Only set if type==1
		int8_t SMTPE_frames_per_second = 0; // 7 bit number ( 6 bit and signed) representing number of SMTPE frames/s. Only set if type==1 
		/**/
	};

	struct DivisionDetails division_details;
};

