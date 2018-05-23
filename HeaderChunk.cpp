#include "stdafx.h"
#include "HeaderChunk.h"

#include <cassert>
#include "Helpers.h"

HeaderChunk::HeaderChunk(std::vector<uint8_t>& data): MIDIChunk(HEADER, data)
{
	Helpers::AssertError(this->GetDataLength() != 6, "Invalid size for header chunk");

	this->format = Helpers::ParseMSBU16(&data[8]);
	this->tracks = Helpers::ParseMSBU16(&data[10]);
	this->division = Helpers::ParseMSBU16(&data[12]);

	Helpers::AssertError(!(format >= 0 && format <= 2), "Format not in range [0, 2]");

	if ((division & CREATE_SINGLEBIT_MASK(15)) == 0)
	{
		this->division_details.type = TICKS_PER_QUARTER_NOTE;
		this->division_details.delta_time_per_quarter = division & CREATE_MULTIBIT_MASK(0, 14);
	}
	else
	{
		this->division_details.type = FRAMES_PER_SECOND_TICKS_PER_FRAME;
		this->division_details.delta_time_per_SMTPE_frame = division & CREATE_MULTIBIT_MASK(0, 7);
		this->division_details.SMTPE_frames_per_second = (int8_t)(division & CREATE_MULTIBIT_MASK(8, 14));
	}
	
}

HeaderChunk::~HeaderChunk()
{
}
