#ifndef myf
#define myf
#include <iostream>


struct determinant
{
	private:
		
		size_t lines;
		
		int** data;

	public:

		determinant(size_t lines);

		determinant(const determinant& m);

		determinant(determinant&& m);
		
		virtual ~determinant();
		
		friend std::ostream& operator<<(std::ostream& out, const determinant &m);
		
		friend std::istream& operator>>(std::istream& in, const determinant &m);

		int logic(const determinant& m,size_t lines);

		int setLines(size_t n) { 
			if (n == 0)throw "lines cant be 0";
			lines = n; }
		int setdata(int row,int column, int n) { data[row][column] = n; }
		int getLines() const  { return lines; }
		int getData(int i,int j) const  { return data[i][j]; }

};

#endif