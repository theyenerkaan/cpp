#include "bsp.hpp"

// Helper function: calculate cross product
// Returns the signed area (direction) of triangle formed by three points
static Fixed crossProduct(Point const& p1, Point const& p2, Point const& p3) {
	return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) 
	     - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

// Check if point is on the same side of all three edges
static bool sameSide(Fixed d1, Fixed d2, Fixed d3) {
	// All positive or all negative
	return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed d1 = crossProduct(a, b, p);
	Fixed d2 = crossProduct(b, c, p);
	Fixed d3 = crossProduct(c, a, p);
	
	// Point is on edge or vertex
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;
	
	// Point must be on same side of all edges
	return sameSide(d1, d2, d3);
}
