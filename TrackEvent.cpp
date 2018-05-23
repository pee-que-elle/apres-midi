#include "stdafx.h"
#include "TrackEvent.h"
#include "Helpers.h"

#include <algorithm>
#include <map>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <iostream>

#define stringtolower(x) std::transform(x.begin(), x.end(), x.begin(), std::tolower);

std::map<Event, std::string> TrackEvent::signatures  =
{

	// Index-based precedence :p
	{ ALL_SOUND_OFF,				"B+ 78 00" },
	{ RESET_ALL_CONTROLLERS,		"B+ 79 00" },
	{ LOCAL_CONTROL,				"B+ 7A -+" },
	{ ALL_NOTES_OFF,				"B+ 7B 00" },
	{ OMNI_MODE_OFF,				"B+ 7C 00" },
	{ OMNI_MODE_ON,					"B+ 7D 00" },
	{ MONO_MODE_ON,					"B+ 7E /0" },
	{ POLY_MODE_ON,					"B+ 7F 00" },

	{ NOTE_OFF,						"8+ -+ -+" },
	{ NOTE_ON,						"9+ -+ -+" },
	{ POLYPHONIC_KEY_PRESSURE,		"A+ -+ -+" },
	{ CONTROLLER_CHANGE,			"B+ -+ -+" },
	{ PROGRAM_CHANGE,				"C+ -+" },
	{ CHANNEL_KEY_PRESSURE,			"D+ -+" },
	{ PITCH_BEND,					"E+ -+ -+" },

	
	{ F0_SYSEX_EVENT,				"F0 LL" },
	{ F7_SYSEX_EVENT,				"F7 LL" },

	{ SEQUENCE_NUMBER,				"FF 00 02 ++ ++" },
	{ TEXT_EVENT,					"FF 01 LL" },
	{ COPYRIGHT_NOTICE,				"FF 02 LL" },
	{ SEQUENCE_OR_TRACK_NAME,		"FF 03 LL" },
	{ INSTRUMENT_NAME,				"FF 04 LL" },
	{ LYRIC,						"FF 05 LL" },
	{ MARKER,						"FF 06 LL" },
	{ CUE_POINT,					"FF 07 LL" },
	{ MIDI_CHANNEL_PREFIX,			"FF 20 01 0+" },
	{ END_OF_TRACK,					"FF 2F 00" },
	{ SET_TEMPO,					"FF 51 03 ++ ++ ++" },
	{ SMTPE_OFFSET,					"FF 54 05 ++ ++ ++ ++ ++" },
	{ TIME_SIGNATURE,				"FF 58 04 ++ ++ ++ ++" },
	{ KEY_SIGNATURE,				"FF 59" },
	{ SEQUENCE_SPECIFIC_META_EVENT, "FF 7F LL" },

	{ UNDEFINED,					"" }

};


TrackEvent::TrackEvent()
{
}
	
void TrackEvent::SetEvent(std::vector<uint8_t>::iterator event, std::vector<uint8_t>::iterator chunk_boundary)
{
	std::tuple<Event, size_t> current_match = std::make_tuple(UNDEFINED, 0);

	for (auto arg : this->signatures)
	{
		// To skip the placeholder enum
		if (arg.first == UNDEFINED) continue;

		// Be sure to not read OOB, check if arg length fits in the buffer
		if ((chunk_boundary - event) < (arg.second.size() + 1) / 3 ) continue;
		
		std::tuple<bool, size_t> potential_match = this->WildcardMatchEvent(event, arg.second);
	
		if (std::get<0>(potential_match))
		{
			current_match = std::make_tuple(arg.first, std::get<1>(potential_match));
			break;
		}
		
	}
	
	Helpers::AssertError(std::get<0>(current_match) == UNDEFINED, "Undefined MIDI event encountered.");
	
	this->type = std::get<0>(current_match);

	auto boundary = event + std::get<1>(current_match) - (this->signatures[std::get<0>(current_match)].size() + 1) / 3;

	this->signature = std::vector<uint8_t>(event, boundary);
	this->data = std::vector<uint8_t>(boundary, event + std::get<1>(current_match));
}

TrackEvent::~TrackEvent()
{
}

std::tuple<bool, size_t> TrackEvent::WildcardMatchEvent(std::vector<std::uint8_t>::iterator data, std::string pattern)
{
	size_t bytes_in_pattern = (pattern.size() + 1) / 3;

	
	std::string data_hex = Helpers::ToHex(std::vector<std::uint8_t>(data, data + bytes_in_pattern) );
	stringtolower(pattern);
	stringtolower(data_hex);

	uint8_t size = 0;

	for (size_t i = 0; i < pattern.size(); ++i)
	{
		// Wildcard checks
		if (
			(
				(pattern[i] == data_hex[i]) ||
				((pattern[i] == '+' || pattern[i] == 'l') && isxdigit(data_hex[i])) ||
				(pattern[i] == '-' && data_hex[i] >= '0' && data_hex[i] <= '7') ||
				(pattern[i] == '/' && data_hex[i] >= '0' && data_hex[i] <= '1')
			) == false
		) return std::make_tuple(false, 0);
		
		if (i != 0 && pattern[i] == 'l' && pattern[i - 1] == 'l')
			size = (uint8_t)strtol(data_hex.substr(i - 1, i + 1).c_str() , NULL, 16);
	}
	return std::make_tuple(true, (pattern.size() + 1) / 3 + size);	
}