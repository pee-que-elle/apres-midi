#pragma once
#include "TrackEvent.h"

#include <map>

namespace Debug
{

	std::map<Event, std::string> event_string_lookup = {
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On"},
	{ POLYPHONIC_KEY_PRESSURE, "Polyphonic Key Pressure"},
	{ CONTROLLER_CHANGE, "Controller Change"},
	{ PROGRAM_CHANGE, "Program Change"},
	{ CHANNEL_KEY_PRESSURE, "Channel Key Pressure" },
	{ PITCH_BEND, "Pitch Bend"},
	{ ALL_SOUND_OFF, "All Sound Off" },
	{ RESET_ALL_CONTROLLERS, "Reset All Controllers"},
	{ LOCAL_CONTROL, "Local Control" },
	{ ALL_NOTES_OFF, "All Notes Off"},
	{ OMNI_MODE_OFF, "Omni Mode Off" },
	{ OMNI_MODE_ON, "Omni Mode On"},
	{ MONO_MODE_ON, "Mono Mode On" },
	{ POLY_MODE_ON, "Poly Mode On"},
	{ F0_SYSEX_EVENT, "F0 System Exclusive Event" },
	{ F7_SYSEX_EVENT, "F7 System Exclusive Event"},
	{ SEQUENCE_NUMBER, "Sequence Number" },
	{ TEXT_EVENT, "Text Event"},
	{ COPYRIGHT_NOTICE, "Copyright Notice" },
	{ SEQUENCE_OR_TRACK_NAME, "Sequence/Track Name"},
	{ INSTRUMENT_NAME, "Instrument Name" },
	{ LYRIC, "Lyric"},
	{ MARKER, "Marker" },
	{ CUE_POINT, "Cue Point"},
	{ MIDI_CHANNEL_PREFIX, "MIDI Channel Prefix" },
	{ END_OF_TRACK, "End Of Track (EOT)"},
	{ SET_TEMPO, "Set Tempo" },
	{ SMTPE_OFFSET, "SMTPE Offset"},
	{ TIME_SIGNATURE, "Time Signature" },
	{ KEY_SIGNATURE, "Key Signature"},
	{ SEQUENCE_SPECIFIC_META_EVENT, "Sequence Specific Meta Event" },
	{ UNDEFINED, "Undefined Placeholder Event" }
	};
}