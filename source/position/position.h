#ifndef __position_h_
#define __position_h_

/** \file position.h
    \brief Definitions for the Star class.

    This file...
*/

#include "../includes/cppstdincludes.h"

/** \brief Position class stores a position in 3d space, and provides basic functions. */
class Position {
public:
    /** \brief Default constructor */
    Position();

    /** \brief Position constructor
        \param x The x coordinate to initialize m_x to.
        \param y The y coordinate to initialize m_y to.
        \param z The z coordinate to initialize m_z to. */
    Position(double x, double y, double z);

    /** \brief Copy constructor
        \param toCopy A refrence to a Position class to copy m_x, m_y, and m_z from */
    Position(Position &toCopy);

    /** \brief Copies the data from the passed Position to this.
        \param toCopy a pointer to the Position class to copy.
        \return Returns 0 on a successful copy. */
    int copy(Position &toCopy);

    /** \brief Calculates the straight-line distance from this position to the passed position.
        \param pos2 A refrence to another Position object.
        \return Returns the distance to the other Position on success. Returns <0.0d on failure. */
    double distanceTo(Position &pos2);

    /** \brief Calculates the straight-line distance from this position to the passed position.
        \param x The X coordinate to measure distance to.
        \param y The Y coordinate to measure distance to.
        \param z The Z coordinate to measure distance to.
        \return Returns the distance to the passed point on success. Returns <0.0d on failure. */
    double distanceTo(double x, double y, double z);

    /** \brief Gets the X coordinate.
        \return Returns the value of m_x. */
    double getx();

    /** \brief Gets the Y coordinate.
        \return Returns the value of m_y. */
    double gety();

    /** \brief Gets the Z coordinate.
        \return Returns the value of m_z. */
    double getz();

    /** \brief Sets the X coordinate.
        \param x Value to set m_x to.
        \return Returns 0*/
    int setx(double x);

    /** \brief Sets the Y coordinate.
        \param y Value to set m_y to.
        \return Returns 0*/
    int sety(double y);

    /** \brief Sets the Z coordinate.
        \param z Value to set m_z to.
        \return Returns 0*/
    int setz(double z);

    /** \brief Moves the X coordinate.
    	\param x The value to add to m_x.
        \return Returns the new value of m_x. */
	double movex(double x);

    /** \brief Moves the Y coordinate.
    	\param y The value to add to m_y.
        \return Returns the new value of m_y. */
	double movey(double y);

    /** \brief Moves the Z coordinate.
    	\param z The value to add to m_z.
        \return Returns the new value of m_z */
	double movez(double z);

    /** \brief Calculates and returns the difference between this and the passed Position's x value. */
	double diffx(Position &pos);

    /** \brief Calculates and returns the difference between this and the passed Position's y value. */
	double diffy(Position &pos);

    /** \brief Calculates and returns the difference between this and the passed Position's z value. */
	double diffz(Position &pos);

private:
    double m_x, m_y, m_z; /**< The x, y, and z coordinates. */
};

#endif
