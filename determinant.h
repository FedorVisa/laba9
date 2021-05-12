#ifndef myf
#define myf
#include <iostream>


class determinant
{
	private:
		
		size_t lines;
		
		int** data;

	public:

		determinant(size_t lines);
		
		virtual ~determinant();
		
		friend std::ostream& operator<<(std::ostream& out, const determinant &m);
		
		friend std::istream& operator>>(std::istream& in, const determinant &m);

		int logic(const determinant& m,size_t lines);

		int determinantCount(const determinant& m, size_t lines);

		int setLines(size_t n) { lines = n; }
		int setdata(int row,int column, int n) { data[row][column] = n; }
		int getLines const () { return lines; }
		int getData const () { return data; }

};

#endif