#include "stdafx.h"
#include "TrackChunk.h"
#include "Helpers.h"
#include "Debug.h"

#include <iomanip>


TrackChunk::TrackChunk(std::vector<uint8_t>& data) : MIDIChunk(TRACK, data)
{

	this->ParseEvents();
}

TrackChunk::~TrackChunk()
{
}

void TrackChunk::ParseEvents()
{
	for (size_t i = 8; i < this->data.size();)
	{
		std::pair<uint32_t, TrackEvent> current;

		size_t deltatime_length = 0;

		while (this->data[i + deltatime_length] & CREATE_SINGLEBIT_MASK(7)) deltatime_length++;

		deltatime_length++;
		
		Helpers::AssertError(deltatime_length > 4, "Error parsing deltatime length. ");
		current.first = Helpers::ParseMSB(&data[i], deltatime_length);
		
		i += deltatime_length;
		current.second.SetEvent(this->data.begin() + i, this->data.end());

		i += current.second.data.size() + current.second.signature.size();
		
		this->pairs.push_back(current);

		//std::cout << std::setw(30) << std::left << Debug::TrackEvent::event_string_lookup[current.second.type] << " : " << Helpers::ToHex(current.second.data) << std::endl;
	}
}