#include "crisscross.hpp"
#include "exceptions.hpp"
#include "matrix.hpp"
#include "words.hpp"

#include <fstream>
#include <iostream>
#include <string>

int main() 
{
		Matrix matrix(15, 15);
		std::string input, output;
//		std::cout << "Input file: ";
//		std::cin >> input;
//		std::cout << "Output file: ";
//		std::cin >> output;
	try
	{
		Words words("input.txt");
		crisscross(words, matrix);
		std::ofstream file("output.txt");
		std::cout << matrix.get_coef() << std::endl;
		file << matrix;
	}
	catch (Exception e)
	{
		std::cout << e << std::endl;
	}
	
	return 0;
}
