#include <iostream>
#include <vector>

using uint = unsigned int;

struct Point
{
	uint x;
	uint y;
	float value;
	
	Point(uint _x, uint _y, float _value = 0):
	x(_x),
	y(_y),
	value(_value)
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
					//std::cout << "(" << M[idx].x << ", " << M[idx].y << ") ";
					std::cout << M[idx].value << " ";
					
				}
				
				std::cout << std::endl;
			}
		}
		
		Point& getElement(uint row, uint col)
		{
			return M[row * c + col];
		}
};

int main()
{
	const uint rows = 10;
	const uint cols = 10;
	
	Grid m(rows, cols);
	
	m.print();
	
	for(uint i = 0; i < rows; i++)
	{
		for(uint j = 0; j < cols; j++)
		{
			m.getElement(i, 0).value = 1;
			m.getElement(0, j).value = 2;
			m.getElement(i, cols-1).value = 3;
			m.getElement(rows-1, j).value = 4;
		}
	}
	
	m.print();
}
