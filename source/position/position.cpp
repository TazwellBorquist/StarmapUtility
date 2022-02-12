/**
    \file position.cpp
    \brief Implementations for member functions of the Position class.
*/

#include "position.h"

// Default constructor: initialize all values to 0.0f.
Position::Position() : m_x(0.0f)
                    ,  m_y(0.0f)
                    ,  m_z(0.0f) {}

// Position constructor: initialize values to x, y, and z.
Position::Position(double x, double y, double z) : m_x(x)
                                                ,  m_y(y)
                                                ,  m_z(z) {}

// Refrence copy constructor: initialize to values of toCopy.
Position::Position(Position &toCopy) : m_x(toCopy.m_x)
                                    ,  m_y(toCopy.m_y)
                                    ,  m_z(toCopy.m_z) {}

// Pointer copy constructor: copy values from toCopy, else set vars to 0.0f.
Position::Position(Position *toCopy) {
    if (copy(toCopy)) // if Position::copy fails
        m_x = m_y = m_z = 0.0f; // initialize positions to 0.0f
}

// copy(Position *toCopy) copies the values from toCopy to this. Returns 0 on
// success, and -1 on failure.
int Position::copy(Position *toCopy) {
    if (!toCopy)
        return -1;

    m_x = toCopy->m_x;
    m_y = toCopy->m_y;
    m_z = toCopy->m_z;

    return 0;
}

// double distanceTo() Calculates and returns the distance from this to pos2.
// Returns -2.0f on math failure, and -1.0f on nullptr failure.
double Position::distanceTo(Position &pos2) {
    return distanceTo(pos2.m_x, pos2.m_y, pos2.m_z);
}

// double distanceTo() Calculates and returns the distance from this to pos2.
// Returns -2.0f on math failure, and -1.0f on nullptr failure.
double Position::distanceTo(Position *pos2) {
    if (!pos2) // if pos2 is NULL
        return -1.0f; // return error

    // pass object as refrence to, and return distanceTo();
    return distanceTo(pos2->m_x, pos2->m_y, pos2->m_z);
}

double Position::distanceTo(double x, double y, double z) {
    std::feclearexcept(FE_OVERFLOW | FE_UNDERFLOW); // over/underflow protection

    x *= x; // x = x^2
    y *= y; // y = y^2
    z *= z; // z = z^2
    x += y + z; // x^2 + y^2 + z^2

    if (std::fetestexcept(FE_OVERFLOW | FE_UNDERFLOW)) // over/underflow protection
        return -2.0f;

    return sqrt(x);
}

// double getX() returns the value of m_x.
double Position::getX() {
	return m_x;
}

// double getY() returns the value of m_y.
double Position::getY() {
	return m_y;
}

// double getZ() returns the value of m_z.
double Position::getZ() {
	return m_z;
}

// int setX(double x) sets the value of m_x to x. Returns 0.
int Position::setX(double x) {
	m_x = x;
	return 0;
}

// int setY(double y) sets the value of m_y to y. Returns 0.
int Position::setY(double y) {
	m_y = y;
	return 0;
}

// int setZ(double z) sets the value of m_z to z. Returns 0.
int Position::setZ(double z) {
	m_z = z;
	return 0;
}

// int moveX(double x) adds the value of x to m_x. Returns the new value of m_x.
double Position::moveX(double x) {
	return m_x += x;
}

// int moveY(double y) adds the value of y to m_y. Returns the new value of m_y.
double Position::moveY(double y) {
	return m_y += y;
}

// int moveZ(double z) adds the value of z to m_z. Returns the new value of m_z.
double Position::moveZ(double z) {
	return m_z += z;
}
