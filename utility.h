/**
 * @file utility.h
 * @author John Sullivan (jsull003 at ucr.edu)
 * @date December 28, 2010
 *
 * @brief Defines useful helper functions
 **/

#pragma once

#include <stdexcept>

#include "error.hpp"

const unsigned int infinity = ~0;

/**
 * @brief Returns the log base 2 of a number @b zvalue.
 **/
inline unsigned int log2(unsigned int zvalue)
{
    // log2(0) is undefined so error
    if (zvalue == 0) ERROR(std::domain_error("Log base 2 of 0 is undefined."));

    unsigned int result = 0;

    // Loop until zvalue equals 0
    while (zvalue)
    {
        zvalue >>= 1;
        ++result;
    }

    return result - 1;
}
