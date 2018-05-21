#include "stdafx.h"
#include "TrackChunk.h"
#include "Helpers.h"

TrackChunk::TrackChunk(std::vector<uint8_t>& data): MIDIChunk(TRACK, data)
{
	this->ParseEvents();
	system("pause");
}


TrackChunk::~TrackChunk()
{
}

void TrackChunk::ParseEvents()
{
	for (unsigned i = 8; i < this->data.size();)
	{
		std::pair<uint32_t, TrackEvent> current;

		size_t deltatime_length;
		for (deltatime_length = 1; (this->data[i + deltatime_length - 1] & CREATE_SINGLEBIT_MASK(7)) != 0; deltatime_length++);
		
		Helpers::AssertError(deltatime_length > 4, "Error parsing deltatime length. ");

		current.first = Helpers::ParseMSB(&data[i], deltatime_length);
		
		i += deltatime_length;

		current.second.SetEvent(this->data.begin() + i, this->data.end());

		i += current.second.data.size() + current.second.signature.size();
		
		this->pairs.push_back(current);

		std::cout << Helpers::ToHex(current.second.data) << std::endl;
	}
}
