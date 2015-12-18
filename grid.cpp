#include <iostream>
#include <vector>
#include <tuple>

using uint = unsigned int;

struct Point
{
	uint x;
	uint y;
	uint data;
	
	Point(uint _x, uint _y, float _data  =0):
	x(_x),
	y(_y),
	data(_data)
	{}
};

class Matrix
{
	std::vector<Point> M;
	uint r;
	uint c;
	public:
		Matrix(uint rows, uint cols): r(rows), c(cols)
		{
			M.reserve(r*c);
			
			for(uint i = 0; i < r; i++)
			{
				for(uint j = 0; j < c; j++)
				{
					M.push_back(Point(i, j));
				}
			}
		}
		
		void print()
		{
			for(uint i = 0; i < r; i++)
			{
				for(uint j = 0; j < c; j++)
				{
					uint idx = c * i + j;
					std::cout << "(" << M[idx].x << ", " << M[idx].y << ") ";
				}
				
				std::cout << std::endl;
			}
		}
};

int main()
{
	Matrix m(5, 5);
	m.print();
}
