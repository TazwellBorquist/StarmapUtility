#ifndef __star_h_
#define __star_h_

/** \file star.h
    \brief Definitions for the Star class.

    This file... */

#include "../includes/cppstdincludes.h"
#include "../position/position.h"

/** \breif Star class stores basic info about one star */
class Star : public Position
{
public:
    Star();

private:
    std::string m_name;
    std::string m_class;
    float m_size, m_brightness;
};

#endif
