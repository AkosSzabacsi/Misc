#include <iostream>
#include <vector>

using uint = unsigned int;

struct Point
{
	uint x;
	uint y;
	uint value;
	
	Point(uint _x, uint _y, float _value = 0):
	x(_x),
	y(_y),
	data(_data)
	{}
};

class Grid
{
	std::vector<Point> M;
	uint r;
	uint c;
	public:
		Grid(uint rows, uint cols): r(rows), c(cols)
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
		
		Point getElement(uint row, uint col)
		{
			return M[row * c + col];
		}
};

int main()
{
	Grid m(10, 10);
	m.print();
	
	std::cout << m.getElement(5,5).x << " " << m.getElement(5,5).y << std::endl;
}
