#pragma once

#include <vector>
#include <cstdint>

class MetaEvent
{
public:
	MetaEvent();
	~MetaEvent();

	enum MetaEventID {
		SEQUENCE_NUMBER, TEXT_EVENT, COPYRIGHT_NOTICE, SEQUENCE_OR_TRACK_NAME, INSTRUMENT_NAME, LYRIC, MARKER, CUE_POINT,
		MIDI_CHANNEL_PREFIX, END_OF_TRACK, SET_TEMPO, SMTPE_OFFSET, TIME_SIGNATURE, KEY_SIGNATURE, SEQUENCE_SPECIFIC_META_EVENT
	};

	enum MetaEventID id;

	std::vector<uint8_t> data;
};

