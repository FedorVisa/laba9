#pragma once
class determinant
{
	private:
		double** data;
		size_t lines;

	public:
		determinant(size_t lines);
		
		determinant(const determinant& m);
		
		virtual ~determinant();
		
		friend std::ostream& operator<<(std::ostream& out, const determinant&m);
		
		friend std::istream& operator>>(std::istream& in, const determinant&m);

};

