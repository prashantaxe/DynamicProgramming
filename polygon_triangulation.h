#ifndef DP3
#define DP03

#include <math.h>

#define INT_MAX 100000.0
struct Point
{
	int x;
	int y;
};

double dist(Point& a, Point& b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


double cost(Point& a, Point& b, Point& c)
{
	return dist(a, b) + dist(b, c) + dist(c, a);
}

/*Write a recursive function to compute Min Cost Triangulation. points[] is all set of points.
points[] is array of all points. start/end is the set of index under consideration for further dividing or triangulating.
*/

double MinCostTriangulation(Point points[], int start, int end)
{
	//If the 2 points are neighbors or they are same, polygon cannot be triangulated.
	if (abs(start - end) <2)
	{
		return 0;
	}
	double min = INT_MAX;
	double min_now = 0;
	//Iterate over all the points in between
	for (int k = start + 1; k < end; k++)
	{
		min_now = 
		
		MinCostTriangulation(points, start, k) 
		+ 
		MinCostTriangulation(points, k, end)
		+
		cost(points[start], points[k], points[end]);

		if (min_now < min)
			min = min_now;
	}

	return min;
}

double MinCostTriangulationMemoized(Point points[], int start, int end, double** table, int n);

double computeMinCostTriangulationMemoized(Point points[], int start, int end)
{
	int size = end - start + 1;
	
	double** table = new double*[size];

	for (int i = 0; i < size; i++)
	{
		*(table + i) = new double[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i][j] = -1.0;
		}
	}
return	MinCostTriangulationMemoized(points, start, end, table, size);
}
//Assumes the table is initialized to -1.
double MinCostTriangulationMemoized(Point points[], int start, int end, double** table, int n)
{
	//If the 2 points are neighbors or they are same, polygon cannot be triangulated.
	if (abs(start - end) <2)
	{
		return 0;
	}
	double min = INT_MAX;
	double min_now = 0;
	//Iterate over all the points in between
	for (int k = start + 1; k < end; k++)
	{
		double a=-1.0, b=-1.0;
		if (table[start][k] != -1)
		{
			a = table[start][k];
		}
		else
		{
			a = MinCostTriangulation(points, start, k);
			table[start][k] = a;
		}

		if (table[k][end] != -1)
		{
			b = table[k][end];
		}
		else
		{
			b = MinCostTriangulation(points, k, end);
			table[k][end] = b;
		}
		min_now =

			a
			+
			b			
			+
			cost(points[start], points[k], points[end]);

		if (min_now < min)
			min = min_now;
	}

	return min;
}

/*
This recursive solution showed above has overlapping solutions. 
e.g start-end index : index 0-7 needs to compute min value for 0-1, 2-7 | 0-2, 3-7 .. etc 
*/
double MinCostTriangulationDP(Point points[], int start, int end)
{
	int size = end - start + 1;

	double** table = new double* [size];
	
	
	for (int i = 0; i < size; i++)
	{
		*(table+i) = new double[size];
	}

	//We finally have to reach interval 0-size-1 
	for (int interval = 0; interval < size; interval++)
	{

		for (int i = 0; i < size - interval; i++)
		{
			int j = i + interval;

			if (interval == 0 || interval == 1)
			{
				table[i][j] = 0;
				continue;
			}

			double min = INT_MAX;
			double curr_min = 0;

			for (int k = i + 1; k < j; k++)
			{
				curr_min = table[i][k] + table[k][j]+cost(points[i], points[j], points[k]);
				if (curr_min < min)
					min = curr_min;
			}

			table[i][j] = min;

		}
	}
	
	return table[0][size-1];
}

#endif