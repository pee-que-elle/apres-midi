#pragma once

#include <vector>
#include <functional>
#include <map>

enum Event
{
	/* MIDI EVENTS */

	// Channel voice messages
	NOTE_OFF = 0, NOTE_ON = 1, POLYPHONIC_KEY_PRESSURE = 2, CONTROLLER_CHANGE = 3, PROGRAM_CHANGE = 4, CHANNEL_KEY_PRESSURE = 5, PITCH_BEND = 6,

	// Channel mode messages
	ALL_SOUND_OFF = 7, RESET_ALL_CONTROLLERS = 8, LOCAL_CONTROL = 9, ALL_NOTES_OFF = 10, OMNI_MODE_OFF = 11, OMNI_MODE_ON = 12, MONO_MODE_ON = 13, POLY_MODE_ON = 14,

	/* SYSEX EVENTS */
	F0_SYSEX_EVENT = 15, F7_SYSEX_EVENT = 16,


	/* META EVENTS */
	SEQUENCE_NUMBER = 17, TEXT_EVENT = 18, COPYRIGHT_NOTICE = 19, SEQUENCE_OR_TRACK_NAME = 20, INSTRUMENT_NAME = 21, LYRIC = 22, MARKER = 23, CUE_POINT = 24,
	MIDI_CHANNEL_PREFIX = 25, END_OF_TRACK = 26, SET_TEMPO = 27, SMTPE_OFFSET = 28, TIME_SIGNATURE = 29, KEY_SIGNATURE = 30, SEQUENCE_SPECIFIC_META_EVENT = 31,

	UNDEFINED = 32
};

class TrackEvent
{
public:
	TrackEvent();

	void SetEvent(std::vector<uint8_t>::iterator event, std::vector<uint8_t>::iterator chunk_boundary);
	~TrackEvent();
	std::tuple<bool, size_t> WildcardMatchEvent(std::vector<std::uint8_t>::iterator data, std::string pattern);

	enum Event type;
	std::vector<uint8_t> signature;
	std::vector<uint8_t> data;

	static std::map<Event, std::string> signatures;

};