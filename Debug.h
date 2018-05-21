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
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" },
	{ NOTE_OFF, "Note Off"},
	{ NOTE_ON, "Note On" }

	};
}