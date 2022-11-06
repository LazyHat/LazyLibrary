#pragma once
#include <stdint.h>
#include "string.cpp"
class ubyte8 : public String
{
    String num = String(8, false);

public:
    ubyte8(uint8_t number);
};