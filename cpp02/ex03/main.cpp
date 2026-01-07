#include "bsp.hpp"
#include <iostream>

static void testPoint(Point const& a, Point const& b, Point const& c, 
                      Point const& p, std::string desc) {
	bool result = bsp(a, b, c, p);
	std::cout << desc << ": " << (result ? "inside" : "outside/edge") << std::endl;
}

int main(void) {
	// Triangle vertices
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);
	
	std::cout << "Triangle vertices: A(0,0) B(10,0) C(5,10)" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	// Test 1: Point clearly inside
	Point p1(5.0f, 5.0f);
	testPoint(a, b, c, p1, "Point(5, 5)   ");
	
	// Test 2: Point outside
	Point p2(15.0f, 5.0f);
	testPoint(a, b, c, p2, "Point(15, 5)  ");
	
	// Test 3: Point on vertex
	Point p3(0.0f, 0.0f);
	testPoint(a, b, c, p3, "Point(0, 0)   ");
	
	// Test 4: Point on edge
	Point p4(5.0f, 0.0f);
	testPoint(a, b, c, p4, "Point(5, 0)   ");
	
	// Test 5: Point close to inside
	Point p5(5.0f, 2.0f);
	testPoint(a, b, c, p5, "Point(5, 2)   ");
	
	// Test 6: Point below triangle
	Point p6(5.0f, -1.0f);
	testPoint(a, b, c, p6, "Point(5, -1)  ");
	
	// Test 7: Another inside point
	Point p7(6.0f, 4.0f);
	testPoint(a, b, c, p7, "Point(6, 4)   ");
	
	// Test 8: Edge case - on slanted edge
	Point p8(7.5f, 5.0f);
	testPoint(a, b, c, p8, "Point(7.5, 5) ");
	
	return 0;
}
