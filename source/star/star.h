#ifndef __star_h_
#define __star_h_

/*!
    \file star.h
    \brief Definitions for the Star class.

    This file...
*/

#include "../includes/cppstdincludes.h"

// Star requires a forward definition of StarMap
class StarMap;

/*!
    \breif Star class stores basic info about one star
*/
class Star
{
public:
    Star();

private:
    /** Name of the star */
    std::string m_name

};

#endif
