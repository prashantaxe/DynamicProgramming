#include <iostream>
#include "polygon_triangulation.h"
int main(int argc, char* argv[])
{
	Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 1 }, { 1, 2 }, { 0, 2 } };
	int n = sizeof(points) / sizeof(points[0]);
	//cout << mTC(points, 0, n - 1);
	//return 0;
	std::cout << MinCostTriangulation(points, 0, n - 1)<<"\n";

	std::cout << computeMinCostTriangulationMemoized(points, 0, n - 1)<<"\n";

	std::cout<< MinCostTriangulationDP(points, 0, n-1) << "\n";
	
	return 0;
}