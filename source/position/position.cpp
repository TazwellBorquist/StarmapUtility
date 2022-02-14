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

// copy(Position &toCopy) copies the values from toCopy to this. Returns 0.
int Position::copy(Position &toCopy) {
    m_x = toCopy.m_x;
    m_y = toCopy.m_y;
    m_z = toCopy.m_z;
    return 0;
}

// double distanceTo() Calculates and returns the distance from this to pos2.
// Returns -1.0f on math failure. Returns the calculated distance otherwise
double Position::distanceTo(Position &pos2) {
    return distanceTo(pos2.m_x, pos2.m_y, pos2.m_z);
}

double Position::distanceTo(double x, double y, double z) {
    x *= x; // x = x^2
    y *= y; // y = y^2
    z *= z; // z = z^2
    x += y + z; // x^2 + y^2 + z^2
    return sqrt(x); // sqrt(x^2 + y^2 + z^2)
}

// double getx() returns the value of m_x.
double Position::getx() {
	return m_x;
}

// double gety() returns the value of m_y.
double Position::gety() {
	return m_y;
}

// double getz() returns the value of m_z.
double Position::getz() {
	return m_z;
}

// int setx(double x) sets the value of m_x to x. Returns 0.
int Position::setx(double x) {
	m_x = x;
	return 0;
}

// int sety(double y) sets the value of m_y to y. Returns 0.
int Position::sety(double y) {
	m_y = y;
	return 0;
}

// int setz(double z) sets the value of m_z to z. Returns 0.
int Position::setz(double z) {
	m_z = z;
	return 0;
}

// int movex(double x) adds the value of x to m_x. Returns the new value of m_x.
double Position::movex(double x) {
	return m_x += x;
}

// int movey(double y) adds the value of y to m_y. Returns the new value of m_y.
double Position::movey(double y) {
	return m_y += y;
}

// int movez(double z) adds the value of z to m_z. Returns the new value of m_z.
double Position::movez(double z) {
	return m_z += z;
}

// Difference between x poses
double Position::diffx(Position &pos) {
    return m_x - pos.m_x;
}

// Difference between y poses
double Position::diffy(Position &pos) {
    return m_y - pos.m_y;
}

// Difference between z poses
double Position::diffz(Position &pos) {
    return m_y - pos.m_y;
}
