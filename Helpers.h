#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

namespace Helpers
{
	void AssertWarn(bool x, std::string y);
	void AssertError(bool x, std::string y);

	uint32_t ParseMSB(uint8_t* buf, size_t bytes);
	uint32_t ParseMSBU32(uint8_t* buf);
	uint16_t ParseMSBU16(uint8_t* buf);

	std::string ToHex(std::vector<uint8_t> data);

}

#define CREATE_SINGLEBIT_MASK(x) \
	1 << x

#define CREATE_MULTIBIT_MASK(x,y) \
	((1ull << (y - x)) - 1ull) << x
