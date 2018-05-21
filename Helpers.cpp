#include "stdafx.h"
#include "Helpers.h"

#include <sstream>
#include <iomanip>

void Helpers::AssertWarn(bool x, std::string y)
{
	
	if (x) std::cout << "[WARNING] " << y << std::endl;
	
}

void Helpers::AssertError(bool x, std::string y)
{
	
	if (x)
	{
		std::cout << "[ERROR] " << y << std::endl;
		system("pause");
		exit(1);
	}

}

std::string Helpers::ToHex(std::vector<uint8_t> data)
{
	std::stringstream ss;
	for (int i = 0; i < data.size(); ++i)
	{
		ss << std::setw(2) << std::setfill('0') << std::hex << (int)data[i];
		if (i != data.size() - 1) ss << " ";
	}
	return ss.str();
}

uint32_t Helpers::ParseMSB(uint8_t* buf, size_t bytes)
{
	uint32_t result = 0;

	for (int i = 0; i < bytes; ++i) result |= (uint32_t)buf[i] << ((bytes * 8) - (8 * (i + 1)));

	return result;
}

uint32_t Helpers::ParseMSBU32(uint8_t* buf)
{
	return ParseMSB(buf, 4);

}

uint16_t Helpers::ParseMSBU16(uint8_t* buf)
{
	return (uint16_t)ParseMSB(buf, 2);
}

