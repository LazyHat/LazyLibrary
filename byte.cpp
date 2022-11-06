#pragma once
#include "byte.h"

ubyte8::ubyte8(uint8_t number)
{
    for (int i = 7; i >= 0; i--)
    {
        if (number == 0)
        {
            this->num[i] = '0';
            continue;
        }
        this->num[i] = (char)(number % 2);
        number /= 2;
    }
}
