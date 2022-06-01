#pragma once
#include "CPolygon.h"

/// Create black circle, with radius in (x,y) = 1 and with center at (0,0,0)
class CCircle : public CPolygon
{
public:
#pragma region CONSTRUCTORs
	/// The basic constructor - creates a new instance of CCircle class with 4 points
	CCircle(void);

	/// A constructor with given number of points - creates a new instance of CCircle class with the given number of points
	/// Parameters:
	///		num_of_points - The number of points
	CCircle(int num_of_points);
#pragma endregion

	/// Change the number of points in the circle. The new circle is black with radius in (x,y) = 1 and and with center at (0,0,0)
	/// Parameters:
	///		num_of_points - The number of points
	void SetNumberOfPoints(int num_of_points);
};
