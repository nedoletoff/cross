#include "crisscross.hpp"
#include "exceptions.hpp"
#include "matrix.hpp"
#include "words.hpp"

#include <fstream>
#include <iostream>

int main() 
{
		Matrix matrix(7, 7);
	try
	{
		Words words("inputfile.txt");
		crisscross(words, matrix);
		std::ofstream file("output.txt");
		std::cout << matrix.get_coef() << std::endl;
		std::cout << matrix.get_unfilled() << std::endl;
		matrix.shrink_to_fit('\0');
		matrix.change_unfilled('\0', ' ');
		file << matrix;
	}
	catch (Exception e)
	{
		std::cout << e << std::endl;
		std::cout << matrix << std::endl;
	}
	
	return 0;
}
